
namespace NewClass2
{
    partial class Calculator
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
            this.tb = new System.Windows.Forms.TextBox();
            this.button0 = new System.Windows.Forms.Button();
            this.buttonP = new System.Windows.Forms.Button();
            this.buttonE = new System.Windows.Forms.Button();
            this.buttonPM = new System.Windows.Forms.Button();
            this.buttonC = new System.Windows.Forms.Button();
            this.buttonDot = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tb
            // 
            this.tb.Location = new System.Drawing.Point(124, 57);
            this.tb.Name = "tb";
            this.tb.Size = new System.Drawing.Size(320, 35);
            this.tb.TabIndex = 0;
            this.tb.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.tb.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // button0
            // 
            this.button0.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button0.Location = new System.Drawing.Point(124, 126);
            this.button0.Name = "button0";
            this.button0.Size = new System.Drawing.Size(60, 60);
            this.button0.TabIndex = 1;
            this.button0.Text = "0";
            this.button0.UseVisualStyleBackColor = true;
            this.button0.Click += new System.EventHandler(this.button0_Click);
            // 
            // buttonP
            // 
            this.buttonP.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.buttonP.Location = new System.Drawing.Point(384, 202);
            this.buttonP.Name = "buttonP";
            this.buttonP.Size = new System.Drawing.Size(60, 60);
            this.buttonP.TabIndex = 2;
            this.buttonP.Text = "+";
            this.buttonP.UseVisualStyleBackColor = true;
            this.buttonP.Click += new System.EventHandler(this.buttonP_Click);
            // 
            // buttonE
            // 
            this.buttonE.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.buttonE.Location = new System.Drawing.Point(384, 351);
            this.buttonE.Name = "buttonE";
            this.buttonE.Size = new System.Drawing.Size(60, 60);
            this.buttonE.TabIndex = 3;
            this.buttonE.Text = "=";
            this.buttonE.UseVisualStyleBackColor = true;
            this.buttonE.Click += new System.EventHandler(this.buttonE_Click);
            // 
            // buttonPM
            // 
            this.buttonPM.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.buttonPM.Location = new System.Drawing.Point(384, 268);
            this.buttonPM.Name = "buttonPM";
            this.buttonPM.Size = new System.Drawing.Size(60, 60);
            this.buttonPM.TabIndex = 4;
            this.buttonPM.Text = "+/-";
            this.buttonPM.UseVisualStyleBackColor = true;
            this.buttonPM.Click += new System.EventHandler(this.buttonPM_Click);
            // 
            // buttonC
            // 
            this.buttonC.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.buttonC.Location = new System.Drawing.Point(384, 126);
            this.buttonC.Name = "buttonC";
            this.buttonC.Size = new System.Drawing.Size(60, 60);
            this.buttonC.TabIndex = 5;
            this.buttonC.Text = "C";
            this.buttonC.UseVisualStyleBackColor = true;
            this.buttonC.Click += new System.EventHandler(this.buttonC_Click);
            // 
            // buttonDot
            // 
            this.buttonDot.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.buttonDot.Location = new System.Drawing.Point(303, 351);
            this.buttonDot.Name = "buttonDot";
            this.buttonDot.Size = new System.Drawing.Size(60, 60);
            this.buttonDot.TabIndex = 6;
            this.buttonDot.Text = ".";
            this.buttonDot.UseVisualStyleBackColor = true;
            this.buttonDot.Click += new System.EventHandler(this.buttonDot_Click);
            // 
            // Calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 597);
            this.Controls.Add(this.buttonDot);
            this.Controls.Add(this.buttonC);
            this.Controls.Add(this.buttonPM);
            this.Controls.Add(this.buttonE);
            this.Controls.Add(this.buttonP);
            this.Controls.Add(this.button0);
            this.Controls.Add(this.tb);
            this.Name = "Calculator";
            this.Text = "Calculator";
            this.Load += new System.EventHandler(this.Calculator_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tb;
        private System.Windows.Forms.Button button0;
        private System.Windows.Forms.Button buttonP;
        private System.Windows.Forms.Button buttonE;
        private System.Windows.Forms.Button buttonPM;
        private System.Windows.Forms.Button buttonC;
        private System.Windows.Forms.Button buttonDot;
    }
}

