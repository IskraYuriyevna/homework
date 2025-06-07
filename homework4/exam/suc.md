```
a := 7;
read b;
while(a<>b){
    if(a<b){
        c := b;
        b := a;
        a := c;
        a := a-b;
    }else{
        a := a - b;
    }
}
write a;
```

```
if(b/7*7<b){
    write 1;
}else{
    write 7;
}
```