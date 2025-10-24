using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UFO
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int timh = 50;
        int timv = 50;
        int holY = 320;
        int verX = 80;
        bool revH = false, revV = false, coll = false;
        int cntc = 0;

        private void Form1_Load(object sender, EventArgs e)
        {
            tbHP.Value = holY;
            tbVP.Value = verX;
            tbHS.Value = timh;
            timerH.Interval = timh;
            timerV.Interval = timv;
            tbVS.Value = timv;
            displayer.Text = cntc.ToString();
            timerC.Enabled = true;
        }

        private void butV_Click(object sender, EventArgs e)
        {
            timerV.Enabled = !timerV.Enabled;
        }

        private void butH_Click(object sender, EventArgs e)
        {
            timerH.Enabled = !timerH.Enabled;
        }

        private void butEx_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void tbHS_Scroll(object sender, EventArgs e)
        {
            timerH.Interval = tbHS.Value;
        }

        private void tbHP_Scroll(object sender, EventArgs e)
        {
            pcH.Top = tbHP.Value/2;
        }

        private void tbVP_Scroll(object sender, EventArgs e)
        {
            pcV.Left = tbVP.Value/2;
        }

        private void tbVS_Scroll(object sender, EventArgs e)
        {
            timerV.Interval = tbVS.Value;
        }

        private void pcV_Click(object sender, EventArgs e)
        {
            timerV.Enabled = !timerV.Enabled;
        }

        private void pcH_Click(object sender, EventArgs e)
        {
            timerH.Enabled = !timerH.Enabled;
        }

        private void timerV_Tick(object sender, EventArgs e)
        {
            if (!revV)
            {
                pcV.Top = pcV.Top + 1;
            }
            else 
            {
                pcV.Top = pcV.Top - 1;
            }
            if (pcV.Top >= 180) {
                revV = true;
            }
            else if (pcV.Top <= 0)
            {
                revV = false;
            }
        }


        private void timerH_Tick(object sender, EventArgs e)
        {
            if (!revH)
            {
                pcH.Left = pcH.Left + 1;
            }
            else 
            {
                pcH.Left = pcH.Left - 1;
            }
            if (pcH.Left >= 180)
            {
                revH = true;
            }
            else if (pcH.Left <= 0)
            {
                revH = false;
            }
        }

        private void timerC_Tick(object sender, EventArgs e)
        {
            collison();
            displayer.Text = cntc.ToString();
        }

        private void collison() 
        {
            double disX = pcV.Left - pcH.Left;
            double disY = pcV.Top - pcH.Top;
            double dist = Math.Sqrt(disX*disX + disY*disY);
            if (!coll) 
            { 
                if (dist<=10) 
                {
                    coll = true;
                    cntc += 1;
                }
            }
            if (dist > 10) coll = false;
        }
    }
}
