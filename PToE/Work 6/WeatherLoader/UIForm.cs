using System;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class UIForm : Form
    {
        Factory factory = new Factory();

        public UIForm()
        {
            InitializeComponent();
            comboBox1.Items.Insert(0, "Open Weather Map");
            comboBox1.Items.Insert(1, "Apixu");
            comboBox1.SelectedIndex = 0;
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            WeatherInfo weather;
            if (comboBox1.SelectedIndex == 0)
                weather = factory.getOpenweathermap().updateWeatherInfo(textBox1.Text);
            else
                weather = factory.getApixu().updateWeatherInfo(textBox1.Text);

            textBox1.Text = weather.town;
            label4.Text = weather.description;
            label6.Text = weather.temp;
            label8.Text = weather.pressure;
            label10.Text = weather.humidity;
            label5.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
        }
    }
}
