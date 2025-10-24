using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//仍然有的问题：连续运算行为与现实的计算器不同，在数字为0的情况下符号键无法给后面按下的数字生效

namespace NewClass2
{
    public partial class Calculator : Form
    {
        public Calculator()
        {
            InitializeComponent();
        }

        enum CalcOp
        { 
            None,
            Add,
            Sub,
            Mul,
            Div
        }

        CalcOp prevOp = CalcOp.None;

        bool needClear = true;
        float prev = 0;
        bool dot = false;

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button0_Click(object sender, EventArgs e)
        {
            if (needClear) 
            {
                tb.Text = "";
                needClear = false;
            }
            if (tb.Text != "0")
            {
                if (tb.Text.Length < 10)
                    tb.Text += ((Button)sender).Text;
            }
            else
            {
                tb.Text = "";
                if (tb.Text.Length < 10)
                    tb.Text += ((Button)sender).Text;
            }
        }

        private void Calculator_Load(object sender, EventArgs e)
        {
            placeBut(button0, 1, 3);
            placeBut(buttonP, 3, 0);
            placeBut(buttonM, 3, 1);
            placeBut(buttonMul, 3, 2);
            placeBut(buttonDiv, 3, 3);
            placeBut(buttonE, 4, 0);
            placeBut(buttonC, 4, 1);
            placeBut(buttonPM, 0, 3);
            placeBut(buttonDot, 2, 3);


            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++)
                {
                    Button b = new Button();
                    b.Parent = this;
                    b.Text = (y * 3 + x + 1).ToString();
                    b.Click += button0_Click;
                    placeBut(b, x, y);
                }
        }

        private void placeBut(Button b, int x, int y)
        {
            b.Size = new Size(40, 40);
            b.Left = tb.Left + 45 * x;
            b.Top = tb.Top + +tb.Height + 5 + y * 45;
            b.Font = new Font("Microsoft Sans Serif",14f);
        }

        private void buttonP_Click(object sender, EventArgs e)
        {
            needClear = true;
            prev = float.Parse(tb.Text);
            prevOp = CalcOp.Add;
        }

        private void buttonE_Click(object sender, EventArgs e)
        {
            float v = float.Parse(tb.Text);

            switch (prevOp)
            {
                case CalcOp.Add:
                    tb.Text = (prev + v).ToString();
                    break;
                case CalcOp.Sub:
                    tb.Text = (prev - v).ToString();
                    break;
                case CalcOp.Mul:
                    tb.Text = (prev * v).ToString();
                    break;
                case CalcOp.Div:
                    if (v == 0)
                    {
                        tb.Text = "Error";
                    }
                    else 
                    { 
                        tb.Text = (prev / v).ToString();
                    }
                    break;
            }
        }

        private void buttonC_Click(object sender, EventArgs e)
        {
            needClear = true;
            dot = false;
            tb.Text = "0";
            prevOp = CalcOp.None;
        }

        private void buttonPM_Click(object sender, EventArgs e)
        {
            if ((tb.Text != "0") && (tb.Text != "")) {
                if (tb.Text[0] == '-')
                    tb.Text = tb.Text.Substring(1);
                else
                    tb.Text = "-" + tb.Text;
            }
        }

        private void buttonDot_Click(object sender, EventArgs e)
        {
            if (!dot)
            {
                if (needClear)
                {
                    tb.Text = "0";
                    needClear = false;
                }
                if (tb.Text.Length < 9)
                {
                    tb.Text += ".";
                }
                dot = true;
            }
        }

        private void buttonM_Click(object sender, EventArgs e)
        {
            needClear = true;
            prev = float.Parse(tb.Text);
            prevOp = CalcOp.Sub;
        }

        private void buttonMul_Click(object sender, EventArgs e)
        {
            needClear = true;
            prev = float.Parse(tb.Text);
            prevOp = CalcOp.Mul;
        }

        private void buttonDiv_Click(object sender, EventArgs e)
        {
            needClear = true;
            prev = float.Parse(tb.Text);
            prevOp = CalcOp.Div;
        }
    }
}
