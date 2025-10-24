using System;//系统功能
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;//图形绘制功能
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;//windows窗体控件

namespace newclass//命名空间newclass，这是这个项目的名字
{
    public partial class Form1 : Form
        //继承自Form的Form1窗体类
    {
        public Form1()
            //Form1的构造函数，只包含一个由设计器生成的，初始化窗体组件的函数
        {
            InitializeComponent();
        }
        //圆心的x，y坐标，半径r，角度参数alpha，方向控制参数p
        int X = 120;
        int Y = 120;
        int R = 50;
        double alpha = 0.0;
        int p = 1;
        //时间间隔初始值t，鼠标按下状态MouseDown，图片飞行状态picfly，鼠标按下时的相对坐标ox，oy
        int t = 100;
        bool mouseDown = false , picfly;
        int ox, oy;

        private void pictureBox1_Click(object sender, EventArgs e)
            //蜘蛛的点击事件
        {
            timer1.Enabled = !timer1.Enabled;//切换计时器开关状态
            pc.BackColor = timer1.Enabled ? Color.Green : Color.Red;//若计时器开，中心点变绿色，否则红色
        }

        private void nudY_ValueChanged(object sender, EventArgs e)
            //将数值调节器的值赋给Y变量（就是调数字的框框）
        {
            Y = (int)nudY.Value;
            pc.Top = Y - pc.Height / 2;
        }

        private void timer1_Tick(object sender, EventArgs e)
            //定时器Tick事件
        {
            Console.WriteLine($"Tick: alpha={alpha}, Left={pictureBox1.Left}");
            alpha += p * 0.05;//角度增加，乘上系数p控制方向
            //计算圆周运动的坐标，减去控件的一半坐标来使控件中心对准轨迹点
            pictureBox1.Left = (int)(X + R * Math.Cos(alpha) - pictureBox1.Width/2);
            pictureBox1.Top = (int)(Y - R * Math.Sin(alpha) - pictureBox1.Height/2);
        }

        private void butGo_Click(object sender, EventArgs e)
            //Go按钮点击事件
        {
            timer1.Enabled = !timer1.Enabled;
            //timer1.Enabled = true;
            pc.BackColor = timer1.Enabled ? Color.Green : Color.Red;
        }

        private void butEx_Click(object sender, EventArgs e)
            //Exit按钮点击事件
        {
            Application.Exit();
        }

        private void nudX_ValueChanged(object sender, EventArgs e)
            //将数值调节器的值赋给X变量
        {
            X = (int)nudX.Value;
            pc.Left = X - pc.Width / 2;
        }

        private void nudR_ValueChanged(object sender, EventArgs e)
            //将数值调节器的值赋给R变量
        {
            R = (int)nudR.Value;
        }

        private void Form1_Load(object sender, EventArgs e)
            //窗体加载事件，会在打开的时候就执行
        {
            //设置x,y,z的初始位置
            nudX.Value = X;
            nudY.Value = Y;
            nudR.Value = R;
            //设置pictureBox1也就是蜘蛛的初始位置
            pictureBox1.Left = X + R - pictureBox1.Width / 2;
            pictureBox1.Top = Y - pictureBox1.Height / 2;
            //设置pc也就是旋转中心点
            pc.Left = X - pc.Width / 2;
            pc.Top = Y - pc.Height / 2;

            trackBar1.Value = t;//设置滑块为初始值t
            timer1.Interval = 100;//设置定时器的初始间隔
            trackBar1.Value = 100;//设置滑块的初始值，注意先在属性中将最大值设置为150，最小值设置为50
            pc.BackColor = Color.Red;//设置pc初始背景色
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
            //复选框状态事件
        {
            p = -p;//改变旋转的方向
        }


        private void trackBar1_Scroll(object sender, EventArgs e)
            //滑块滚动事件
        {
            timer1.Interval = trackBar1.Value;//把滑块的值赋给计时器的间隔
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
            //鼠标抬起的事件
        {
            int xx = pictureBox1.Left + pictureBox1.Width / 2;
            int yy = pictureBox1.Top + pictureBox1.Height / 2;

            R = (int)Math.Sqrt((xx - X)*(xx - X) + (yy - Y)*(yy - Y));
            if (R > 200) R = 200; 
            nudR.Value = R;

            if (xx > X)
            {
                alpha = -Math.Atan((double)(yy - Y) / (xx - X));
            }
            else if (xx < X)
            {
                    alpha = Math.PI + Math.Atan((double)(Y - yy) / (xx - X));
            }
            else 
            { 
                alpha = Math.Sign(yy - Y) * Math.PI / 2;
            }

            pictureBox1.Left = (int)(X + R * Math.Cos(alpha) - pictureBox1.Width / 2);
            pictureBox1.Top = (int)(Y - R * Math.Sin(alpha) - pictureBox1.Height / 2);
            //给的代码有问题，符号是错的

            timer1.Enabled = picfly;//恢复鼠标按下之前计时器的状态
            mouseDown = false;

            pc.BackColor = timer1.Enabled ? Color.Green : Color.Red;
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
            //鼠标按下的事件
        {
            mouseDown = true;//设置鼠标为按下的状态
            picfly = timer1.Enabled;//将picfly设置为计时器开启的状态
            timer1.Enabled = false;//暂停计时器
            ox = e.X;oy = e.Y;//记录下鼠标按下时的x，y坐标
            pc.BackColor = Color.Red;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
            //鼠标移动事件
        {
            if (mouseDown) {//如果鼠标是按下的状态
                pictureBox1.Top += e.Y - oy;//更新top的事件
                pictureBox1.Left += e.X - ox;//更新Left的事件a
            }
        }
    }
}
