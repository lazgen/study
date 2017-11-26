using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class UIForm : Form
    {
        Factory factory = new Factory();

        public UIForm()
        {
            InitializeComponent();
            List<string> services = factory.services();
            for (int i = 0; i < services.Count; i++) 
            {
                comboBox1.Items.Insert(i, services[i]);
            }

            comboBox1.SelectedIndex = 0;
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            WeatherInfo weather = factory.getService(comboBox1.SelectedIndex).updateWeatherInfo(textBox1.Text);

            textBox1.Text = weather.town;
            label4.Text = weather.description;
            label6.Text = weather.temp;
            label8.Text = weather.pressure;
            label10.Text = weather.humidity;
            label5.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
        }
    }
}
