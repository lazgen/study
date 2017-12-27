namespace WeatherLoader
{
    partial class UIForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.updateButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.mainInfoOWM = new System.Windows.Forms.Label();
            this.updTimeOWM = new System.Windows.Forms.Label();
            this.tempOWM = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.pressureOWM = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.townTextBox = new System.Windows.Forms.TextBox();
            this.humidityOWM = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.humidityApixu = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.pressureApixu = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.tempApixu = new System.Windows.Forms.Label();
            this.updTimeApixu = new System.Windows.Forms.Label();
            this.mainInfoApixu = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.checkBoxOWM = new System.Windows.Forms.CheckBox();
            this.checkBoxApixu = new System.Windows.Forms.CheckBox();
            this.updInterval = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // updateButton
            // 
            this.updateButton.Location = new System.Drawing.Point(337, 263);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(75, 23);
            this.updateButton.TabIndex = 0;
            this.updateButton.Text = "Apply";
            this.updateButton.UseVisualStyleBackColor = true;
            this.updateButton.Click += new System.EventHandler(this.updateButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(174, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(62, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Weather in ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 132);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Update time:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 56);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(57, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "Temp (°C):";
            // 
            // mainInfoOWM
            // 
            this.mainInfoOWM.AutoSize = true;
            this.mainInfoOWM.Location = new System.Drawing.Point(87, 24);
            this.mainInfoOWM.Name = "mainInfoOWM";
            this.mainInfoOWM.Size = new System.Drawing.Size(10, 13);
            this.mainInfoOWM.TabIndex = 4;
            this.mainInfoOWM.Text = "-";
            // 
            // updTimeOWM
            // 
            this.updTimeOWM.AutoSize = true;
            this.updTimeOWM.Location = new System.Drawing.Point(124, 132);
            this.updTimeOWM.Name = "updTimeOWM";
            this.updTimeOWM.Size = new System.Drawing.Size(10, 13);
            this.updTimeOWM.TabIndex = 5;
            this.updTimeOWM.Text = "-";
            // 
            // tempOWM
            // 
            this.tempOWM.AutoSize = true;
            this.tempOWM.Location = new System.Drawing.Point(123, 56);
            this.tempOWM.Name = "tempOWM";
            this.tempOWM.Size = new System.Drawing.Size(10, 13);
            this.tempOWM.TabIndex = 6;
            this.tempOWM.Text = "-";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(8, 104);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(79, 13);
            this.label7.TabIndex = 7;
            this.label7.Text = "Pressure (hPa):";
            // 
            // pressureOWM
            // 
            this.pressureOWM.AutoSize = true;
            this.pressureOWM.Location = new System.Drawing.Point(123, 104);
            this.pressureOWM.Name = "pressureOWM";
            this.pressureOWM.Size = new System.Drawing.Size(10, 13);
            this.pressureOWM.TabIndex = 8;
            this.pressureOWM.Text = "-";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 132);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(0, 13);
            this.label9.TabIndex = 9;
            // 
            // townTextBox
            // 
            this.townTextBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.townTextBox.Location = new System.Drawing.Point(253, 12);
            this.townTextBox.Name = "townTextBox";
            this.townTextBox.Size = new System.Drawing.Size(148, 20);
            this.townTextBox.TabIndex = 10;
            this.townTextBox.Text = "Kaliningrad";
            this.townTextBox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // humidityOWM
            // 
            this.humidityOWM.AutoSize = true;
            this.humidityOWM.Location = new System.Drawing.Point(124, 80);
            this.humidityOWM.Name = "humidityOWM";
            this.humidityOWM.Size = new System.Drawing.Size(10, 13);
            this.humidityOWM.TabIndex = 12;
            this.humidityOWM.Text = "-";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(9, 80);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(67, 13);
            this.label11.TabIndex = 11;
            this.label11.Text = "Humidity (%):";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(66, 62);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(101, 13);
            this.label12.TabIndex = 13;
            this.label12.Text = "Open Weather Map";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(340, 67);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(33, 13);
            this.label13.TabIndex = 24;
            this.label13.Text = "Apixu";
            // 
            // humidityApixu
            // 
            this.humidityApixu.AutoSize = true;
            this.humidityApixu.Location = new System.Drawing.Point(130, 76);
            this.humidityApixu.Name = "humidityApixu";
            this.humidityApixu.Size = new System.Drawing.Size(10, 13);
            this.humidityApixu.TabIndex = 23;
            this.humidityApixu.Text = "-";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(15, 76);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(67, 13);
            this.label15.TabIndex = 22;
            this.label15.Text = "Humidity (%):";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(14, 128);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(0, 13);
            this.label16.TabIndex = 21;
            // 
            // pressureApixu
            // 
            this.pressureApixu.AutoSize = true;
            this.pressureApixu.Location = new System.Drawing.Point(129, 100);
            this.pressureApixu.Name = "pressureApixu";
            this.pressureApixu.Size = new System.Drawing.Size(10, 13);
            this.pressureApixu.TabIndex = 20;
            this.pressureApixu.Text = "-";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(14, 100);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(79, 13);
            this.label18.TabIndex = 19;
            this.label18.Text = "Pressure (hPa):";
            // 
            // tempApixu
            // 
            this.tempApixu.AutoSize = true;
            this.tempApixu.Location = new System.Drawing.Point(129, 52);
            this.tempApixu.Name = "tempApixu";
            this.tempApixu.Size = new System.Drawing.Size(10, 13);
            this.tempApixu.TabIndex = 18;
            this.tempApixu.Text = "-";
            // 
            // updTimeApixu
            // 
            this.updTimeApixu.AutoSize = true;
            this.updTimeApixu.Location = new System.Drawing.Point(130, 128);
            this.updTimeApixu.Name = "updTimeApixu";
            this.updTimeApixu.Size = new System.Drawing.Size(10, 13);
            this.updTimeApixu.TabIndex = 17;
            this.updTimeApixu.Text = "-";
            // 
            // mainInfoApixu
            // 
            this.mainInfoApixu.AutoSize = true;
            this.mainInfoApixu.Location = new System.Drawing.Point(93, 20);
            this.mainInfoApixu.Name = "mainInfoApixu";
            this.mainInfoApixu.Size = new System.Drawing.Size(10, 13);
            this.mainInfoApixu.TabIndex = 16;
            this.mainInfoApixu.Text = "-";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(14, 52);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(57, 13);
            this.label22.TabIndex = 15;
            this.label22.Text = "Temp (°C):";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(15, 128);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(67, 13);
            this.label23.TabIndex = 14;
            this.label23.Text = "Update time:";
            // 
            // checkBoxOWM
            // 
            this.checkBoxOWM.AutoSize = true;
            this.checkBoxOWM.Location = new System.Drawing.Point(45, 62);
            this.checkBoxOWM.Name = "checkBoxOWM";
            this.checkBoxOWM.Size = new System.Drawing.Size(15, 14);
            this.checkBoxOWM.TabIndex = 25;
            this.checkBoxOWM.UseVisualStyleBackColor = true;
            this.checkBoxOWM.CheckedChanged += new System.EventHandler(this.checkBoxOWM_CheckedChanged);
            // 
            // checkBoxApixu
            // 
            this.checkBoxApixu.AutoSize = true;
            this.checkBoxApixu.Location = new System.Drawing.Point(316, 66);
            this.checkBoxApixu.Name = "checkBoxApixu";
            this.checkBoxApixu.Size = new System.Drawing.Size(15, 14);
            this.checkBoxApixu.TabIndex = 26;
            this.checkBoxApixu.UseVisualStyleBackColor = true;
            this.checkBoxApixu.CheckedChanged += new System.EventHandler(this.checkBoxApixu_CheckedChanged);
            // 
            // updInterval
            // 
            this.updInterval.Location = new System.Drawing.Point(223, 265);
            this.updInterval.Name = "updInterval";
            this.updInterval.Size = new System.Drawing.Size(100, 20);
            this.updInterval.TabIndex = 27;
            this.updInterval.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.updInterval_KeyPress);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(107, 268);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(104, 13);
            this.label4.TabIndex = 28;
            this.label4.Text = "Update interval (ms):";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.mainInfoOWM);
            this.groupBox1.Controls.Add(this.updTimeOWM);
            this.groupBox1.Controls.Add(this.tempOWM);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.pressureOWM);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.humidityOWM);
            this.groupBox1.Location = new System.Drawing.Point(28, 78);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(232, 163);
            this.groupBox1.TabIndex = 29;
            this.groupBox1.TabStop = false;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.mainInfoApixu);
            this.groupBox2.Controls.Add(this.label23);
            this.groupBox2.Controls.Add(this.label22);
            this.groupBox2.Controls.Add(this.updTimeApixu);
            this.groupBox2.Controls.Add(this.tempApixu);
            this.groupBox2.Controls.Add(this.label18);
            this.groupBox2.Controls.Add(this.pressureApixu);
            this.groupBox2.Controls.Add(this.humidityApixu);
            this.groupBox2.Controls.Add(this.label16);
            this.groupBox2.Controls.Add(this.label15);
            this.groupBox2.Location = new System.Drawing.Point(302, 82);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(232, 159);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            // 
            // UIForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 311);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.updInterval);
            this.Controls.Add(this.checkBoxApixu);
            this.Controls.Add(this.checkBoxOWM);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.townTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.updateButton);
            this.Name = "UIForm";
            this.Text = "Work 6  - Factory";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button updateButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label mainInfoOWM;
        private System.Windows.Forms.Label updTimeOWM;
        private System.Windows.Forms.Label tempOWM;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label pressureOWM;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox townTextBox;
        private System.Windows.Forms.Label humidityOWM;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label humidityApixu;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label pressureApixu;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label tempApixu;
        private System.Windows.Forms.Label updTimeApixu;
        private System.Windows.Forms.Label mainInfoApixu;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.CheckBox checkBoxOWM;
        private System.Windows.Forms.CheckBox checkBoxApixu;
        private System.Windows.Forms.TextBox updInterval;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
    }
}

