
namespace UFO
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.butV = new System.Windows.Forms.Button();
            this.butH = new System.Windows.Forms.Button();
            this.butEx = new System.Windows.Forms.Button();
            this.tbHS = new System.Windows.Forms.TrackBar();
            this.tbHP = new System.Windows.Forms.TrackBar();
            this.tbVP = new System.Windows.Forms.TrackBar();
            this.tbVS = new System.Windows.Forms.TrackBar();
            this.Vertical = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pcV = new System.Windows.Forms.PictureBox();
            this.pcH = new System.Windows.Forms.PictureBox();
            this.timerV = new System.Windows.Forms.Timer(this.components);
            this.timerH = new System.Windows.Forms.Timer(this.components);
            this.label5 = new System.Windows.Forms.Label();
            this.displayer = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.timerC = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.tbHS)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbHP)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVP)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVS)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pcV)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pcH)).BeginInit();
            this.SuspendLayout();
            // 
            // butV
            // 
            this.butV.Location = new System.Drawing.Point(863, 54);
            this.butV.Name = "butV";
            this.butV.Size = new System.Drawing.Size(150, 93);
            this.butV.TabIndex = 0;
            this.butV.Text = "Vertical UFO stop/start";
            this.butV.UseVisualStyleBackColor = true;
            this.butV.Click += new System.EventHandler(this.butV_Click);
            // 
            // butH
            // 
            this.butH.Location = new System.Drawing.Point(863, 188);
            this.butH.Name = "butH";
            this.butH.Size = new System.Drawing.Size(150, 87);
            this.butH.TabIndex = 1;
            this.butH.Text = "Horizontal UFO stop/start";
            this.butH.UseVisualStyleBackColor = true;
            this.butH.Click += new System.EventHandler(this.butH_Click);
            // 
            // butEx
            // 
            this.butEx.Location = new System.Drawing.Point(863, 663);
            this.butEx.Name = "butEx";
            this.butEx.Size = new System.Drawing.Size(150, 88);
            this.butEx.TabIndex = 2;
            this.butEx.Text = "Exit";
            this.butEx.UseVisualStyleBackColor = true;
            this.butEx.Click += new System.EventHandler(this.butEx_Click);
            // 
            // tbHS
            // 
            this.tbHS.Location = new System.Drawing.Point(361, 631);
            this.tbHS.Maximum = 100;
            this.tbHS.Minimum = 10;
            this.tbHS.Name = "tbHS";
            this.tbHS.Size = new System.Drawing.Size(420, 90);
            this.tbHS.TabIndex = 3;
            this.tbHS.Value = 10;
            this.tbHS.Scroll += new System.EventHandler(this.tbHS_Scroll);
            // 
            // tbHP
            // 
            this.tbHP.Location = new System.Drawing.Point(361, 711);
            this.tbHP.Maximum = 360;
            this.tbHP.Name = "tbHP";
            this.tbHP.Size = new System.Drawing.Size(432, 90);
            this.tbHP.TabIndex = 4;
            this.tbHP.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.tbHP.Scroll += new System.EventHandler(this.tbHP_Scroll);
            // 
            // tbVP
            // 
            this.tbVP.Location = new System.Drawing.Point(200, 93);
            this.tbVP.Maximum = 360;
            this.tbVP.Name = "tbVP";
            this.tbVP.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.tbVP.Size = new System.Drawing.Size(90, 438);
            this.tbVP.TabIndex = 5;
            this.tbVP.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.tbVP.Value = 10;
            this.tbVP.Scroll += new System.EventHandler(this.tbVP_Scroll);
            // 
            // tbVS
            // 
            this.tbVS.Location = new System.Drawing.Point(80, 93);
            this.tbVS.Maximum = 100;
            this.tbVS.Minimum = 10;
            this.tbVS.Name = "tbVS";
            this.tbVS.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.tbVS.Size = new System.Drawing.Size(90, 438);
            this.tbVS.TabIndex = 6;
            this.tbVS.Value = 10;
            this.tbVS.Scroll += new System.EventHandler(this.tbVS_Scroll);
            // 
            // Vertical
            // 
            this.Vertical.AutoSize = true;
            this.Vertical.Location = new System.Drawing.Point(3, 43);
            this.Vertical.Name = "Vertical";
            this.Vertical.Size = new System.Drawing.Size(226, 24);
            this.Vertical.TabIndex = 7;
            this.Vertical.Text = "Vertical UFO Speed";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(134, 558);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 24);
            this.label2.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(112, 558);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(226, 24);
            this.label1.TabIndex = 11;
            this.label1.Text = "Vertical UFO Place";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(92, 727);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(250, 24);
            this.label3.TabIndex = 12;
            this.label3.Text = "Horizontal UFO Place";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(92, 643);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(250, 24);
            this.label4.TabIndex = 13;
            this.label4.Text = "Horizontal UFO Speed";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panel1.Controls.Add(this.pictureBox2);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Controls.Add(this.pcV);
            this.panel1.Controls.Add(this.pcH);
            this.panel1.Location = new System.Drawing.Point(338, 54);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(400, 400);
            this.panel1.TabIndex = 14;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(437, 3);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(10, 10);
            this.pictureBox2.TabIndex = 3;
            this.pictureBox2.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(50, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(100, 50);
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // pcV
            // 
            this.pcV.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.pcV.Image = ((System.Drawing.Image)(resources.GetObject("pcV.Image")));
            this.pcV.Location = new System.Drawing.Point(80, 60);
            this.pcV.Name = "pcV";
            this.pcV.Size = new System.Drawing.Size(45, 45);
            this.pcV.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pcV.TabIndex = 1;
            this.pcV.TabStop = false;
            this.pcV.Click += new System.EventHandler(this.pcV_Click);
            // 
            // pcH
            // 
            this.pcH.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.pcH.Image = ((System.Drawing.Image)(resources.GetObject("pcH.Image")));
            this.pcH.Location = new System.Drawing.Point(80, 320);
            this.pcH.Name = "pcH";
            this.pcH.Size = new System.Drawing.Size(45, 45);
            this.pcH.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pcH.TabIndex = 0;
            this.pcH.TabStop = false;
            this.pcH.Click += new System.EventHandler(this.pcH_Click);
            // 
            // timerV
            // 
            this.timerV.Tick += new System.EventHandler(this.timerV_Tick);
            // 
            // timerH
            // 
            this.timerH.Tick += new System.EventHandler(this.timerH_Tick);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(0, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(82, 24);
            this.label5.TabIndex = 15;
            this.label5.Text = "label5";
            // 
            // displayer
            // 
            this.displayer.AutoSize = true;
            this.displayer.Location = new System.Drawing.Point(859, 430);
            this.displayer.Name = "displayer";
            this.displayer.Size = new System.Drawing.Size(22, 24);
            this.displayer.TabIndex = 16;
            this.displayer.Text = "0";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(0, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(82, 24);
            this.label6.TabIndex = 17;
            this.label6.Text = "label6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(888, 430);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(154, 24);
            this.label7.TabIndex = 18;
            this.label7.Text = "collision(s)";
            // 
            // timerC
            // 
            this.timerC.Tick += new System.EventHandler(this.timerC_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1054, 829);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.displayer);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Vertical);
            this.Controls.Add(this.tbVS);
            this.Controls.Add(this.tbVP);
            this.Controls.Add(this.tbHP);
            this.Controls.Add(this.tbHS);
            this.Controls.Add(this.butEx);
            this.Controls.Add(this.butH);
            this.Controls.Add(this.butV);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tbHS)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbHP)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVP)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tbVS)).EndInit();
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pcV)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pcH)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button butV;
        private System.Windows.Forms.Button butH;
        private System.Windows.Forms.Button butEx;
        private System.Windows.Forms.TrackBar tbHS;
        private System.Windows.Forms.TrackBar tbHP;
        private System.Windows.Forms.TrackBar tbVP;
        private System.Windows.Forms.TrackBar tbVS;
        private System.Windows.Forms.Label Vertical;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pcV;
        private System.Windows.Forms.PictureBox pcH;
        private System.Windows.Forms.Timer timerV;
        private System.Windows.Forms.Timer timerH;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label displayer;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Timer timerC;
    }
}

