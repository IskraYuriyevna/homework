# SASM cheat sheet
* 这篇文章用于帮助学习和随时回忆起X86汇编语言，准确的说是SASM的知识。  
* 如果您是首次学习汇编语言，请阅读内容更加完善的文献，如《汇编语言程序设计》，《深入了解计算机系统》等书籍。

## 一.安装
* `sudo pacman -S sasm`,这是在Archlinux上安装的方法，在其他系统上有类似的方法。如果要在图形系统安装，请到官网下载对应系统的安装程序。
* 在vscode上调试SASM基本行不通，不建议浪费时间。在OnlineGDB上也不一定可以，总是还是建议安装SASM。

## 二.辞典
* 以下的指令中,若无特殊说明，a必须为寄存器，而b可以是寄存器或立即数
### 1.常用基本运算
* `add a,b` 将a和b相加，并将结果存储在a中
* `inc a` 寄存器a数值加一
* `sub a,b` 将a和b相减，并将结果存储在a中（是用a减去b）
* `dec a` 寄存器a数值减一
* `mul a,b` 有符号乘法，将a和b相乘，并将结果存储在a中
* `imul a,b` 无符号乘法，将a和b相乘，并将结果存储在a中
* `div b` 有符号除法，将被除数除以b,注意b只能是寄存器,需要把除数先保存在寄存器中.
* `idiv b` 无符号除法，将被除数处以b,除法会单独讲.
* `mov a,b` 将b中的数字存入a，也常常使用立即数来给a赋值
* `cdq` 将eax的第31位(符号位)扩展到edx的每一位上,在进行除法之前使用.(有一些类似的其他指令但是我们用不到)
* 单独说说除法:`div`和`idiv`都只有一个操作数,也就是除数,除数必须保存在寄存器中,而被除数保存在:
    * ax中,如果除数是8位,此时商保存在al,余数保存在ah
    * dx:ax中,如果除数是16位,此时商保存在ax,余数保存在dx
    * edx:eax中,如果除数是32位,此时商保存在eax,余数保存在edx
    * 也就是说,之前的被除数会被用于保存商和余数,如果被除数不足32位或需要连除可以使用`cdq`指令来清理edx

### 2.寄存器
* 基本寄存器：eax,ebx,ecx,edx,edi,esi，这些寄存器是32位的。eax是所有函数默认返回出口.
* 对应的16位存储器：ax,bx,cx,dx,si,di,也就是上面这些存储器的低16位。
* ah代表ax的高8位，al代表ax的低8位，以此类推。但除了前四个之外后面的都没有高8位的用法。
* 对应的64位寄存器：rax,rbx,rcx,rdx,rsi,rdi,另外有r8~r15,这些我们不用。
* 注意如果同一句指令同时使用了32位和64位寄存器,64位存储器的高32位也会被置0.
* 理论上r8w到r15w也能用（代表r8到r15的低16位），但是没必要。
* 特殊的寄存器：ebp（基址指针寄存器）和esp（程序栈顶指针）
* ebp: 保存的是系统栈最上面一个栈帧的底部,实际上都被借用来保存esp
* esp：保存程序栈顶的位置,关于程序栈会在函数部分详细说明.
* 条件码寄存器:
    > 条件跳转的时候会根据这几个来决定是否跳转.
    * CF(进位标志) 最高位进位时置1
    * ZF(零标志) 最近的操作结果等于0时置1
    * SF(符号标志) 最近的操作<0时置1
    * OF(溢出标识) 最近的操作发生正负溢出时置1  
    

### 3.逻辑运算
* `and a,b` 将a和b按位与，并将结果存储在a中
* `or a,b` 将a和b按位或，并将结果存储在a中
* `not a` 将a按位取反，并将结果存储在a中
* `xor a,b` 将a和b按位异或，并将结果存储在a中
* `rol a,b` 将a的二进制向左"旋转"b位，并将结果存储在a中。注意和下面的指令一样，b如果是寄存器必须是8位的。
* `ror a,b` 将a的二进制向右"旋转"b位，并将结果存储在a中。
* `shr a,b` 将a的二进制向右"移动"b位，并将结果存储在a中。
* `shl a,b` 将a的二进制向左"移动"b位，并将结果存储在a中。
* `sar a,b` 将a的二进制向右"移动"b位，并将结果存储在a中。
* `sal a,b` 将a的二进制向左"移动"b位，并将结果存储在a中。

### 4.跳转和条件跳转
* 任何跳转指令之后必须带跳转`jmp .a`，对于无条件跳转以外的跳转指令，是根据决定是否跳转的
* 我们约定`.a:`这样带点的标志用于跳转,`a:`这样不带点的标志用于函数,不这样做也不会怎么样.
* `jmp` 无条件转移
* `cmp a,b` 比较a和b的大小,如果a比b小会将CF置1,如果相等会将ZF置1,相当于一次不保存结果的相减
* `test a,b` 主要用于判断寄存器是否为0(如`test eax,eax`),相当于一次不保存结果的按位与
* `ja jnbe` 有符号大于
* `jae jnb` 有符号大于或等于
* `jb jnae` 有符号小于
* `jbe jna` 有符号小于或等于
* `jg jnle` 无符号大于
* `jge jnl` 无符号大于或等于
* `jl jnge` 无符号小于
* `jle jng` 无符号小于或等于
* `je jz` 等于
* `jne jne` 不等于
* `jc` 进位时
* `jnc` 不进位时
* `jnp jpo` 奇偶性为奇数时
* `jp jpe` 奇偶性为偶数时
* `jo` 溢出时
* `jno` 无溢出时
* `js` 符号为为0时
* `jns` 符号为为1时
* 条件码寄存器包含几个标志:CF,ZF,SF,OF

### 5.循环
* `loop` 用法为`loop .a`,表示将.a段的程序循环ecx次,每循环一次ecx的值会减一.
* 通过跳转来进行循环，在循环中设置条件跳转来跳出。

### 6.输入和输出
* 在SASM中采用宏来完成输入输出，首先需要`%include "io.inc"。
* 下面的b是输入的数据尺寸(字节),如`GET_DEC 4,eax`,注意这个尺寸必须和寄存器匹配,否则会报错.
* `GET_CHAR a` 读取字符串并保存在a中
* `GET_DEC b,a` 读取长度为b的十进制数并保存在a中
* `GET_UDEC b,a` 读取长度为b的无符号十进制数并保存在a中
* `NEWLINE` 换行输出
* `PRINT_CHAR b` 输出字符串b或保存在b中的字符串,注意直接输出需要用引号""把字符串阔起来.
* `PRINT_DEC b,a` 输出长度为b的无符号整数a,a可以立即数或者寄存器
* `PRINT_UDEC b,a` 输出长度为b的无符号整数a,同上
* 注意所有字母必须大写，输入数字的类型与后面的操作应当匹配，输入的数字大小与寄存器一致（eax等为4,cl等寄存器为1）

### 7.定义初始化数据,数组,内存寻址
* `db` 
* `dw` 
* `dd` 
* `dq` 
* `resb` 
* `resw` 
* `resd` 
* `equ` 
* `lea a,b` 加载有效地址,将b对应的地址加载到寄存器a中

### 8.其他特性
* `xor eax,eax` 用于在程序最后将eax置零，由于eax是函数出口，最后的ret会使main函数输出0,也就是`return 0`（没有这一句会报错）
* `nop` 空操作,用于对齐
* `section .data`
* `section .bss`
* `section .text`
* `ret` 返回函数(会继续执行call的下一句)
* `call` 执行函数,后面需要带函数标志
* `push a` 将寄存器a的内容压入栈顶
* `pop a` 将栈顶内容弹出并存入寄存器a
* `cmc`进位标志取反`lock`封锁总线`esc`转换到外存储器`wait`cpu进入等待状态`hlt`处理器暂停知道中断或复位信号`std`置方向标志`cld`清方向标志`sti`置中断标志`cli`清中断标志`int`中断`into`溢出中断`iret`中断返回,等等等等,这些指令我们不会用.
    > 什么?你觉得太复杂太麻烦?快加入Risc-V神教吧!Risc-V相比x86具有低功耗,低成本,开源开放,可模块化,简洁等优点,如果你已经对x86的历史包袱感到厌烦了,Risc-V将会为你节省大量的生命(bushi

## 三.示例和技巧
### 1.除法
* 除法的原理在前面讲过,此处给出一个较为完整的程序,后面的示例只会给出关键部分
```C
%include "io.inc" ;导入输入输出的伪指令
section .text ;
global CMAIN ;声明c程序的main函数
CMAIN: ;下面是main函数的部分
    GET_DEC 4,eax ;来自io.inc的伪指令,接受输入并保存在eax中
    mov ecx,4 ;将除数4保存在ecx中,也就是给ecx赋值为4
    cdq ;将eax的符号为扩展到edx中,edx作为高位,eax作为低位,共同作为这个
    div ebx ;将edx:eax除以ebx,也就是除以4,商将会保存在eax中,余数将会保存在edx中
    PRINT_DEC 4,eax ;伪指令,输出eax的值
    xor eax, eax ;将eax置0,此时eax是CMAIN函数的出口
    ret ;向操作系统返回CMAIN函数的值,也就是0
```

### 2.循环
* 使用loop
```
    

```
* 使用跳转
```

```

### 3.位操作
* `xor a,a` 来给某个寄存器置0
* ``
* ``
* ``
* ``

### 4.数组
* 

### 5.函数
* 程序栈:


## 四.软件操作
* `F5` 调试程序的快捷键，程序会构建后停在第一步。
* `F9` 运行程序的快捷键，程序会自动构建并运行和输出。  
* `F10` 在使用`F5`进入调试模式之后，每按一下`F10`程序会运行一步，也就是汇编语言的一个语句。
* 在调试中可以在**调试**菜单中打开各个寄存器和内存中数组的值的显示，显示数组中值的方法是将数组变量填入"变量或表达式"内，在"Array size"内填入数组大小。

## 五.常见问题
* 
* 
* 
* 
* 