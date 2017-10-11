using System;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class Facade : Form
    {
        Loader loader = new Loader();
        Parser parser = new Parser();
        WeatherInfo weather = new WeatherInfo();

        public Facade()
        {
            InitializeComponent();
        }

        private void updateWeather()
        {
            weather = parser.parse(loader.load());

            label4.Text = weather.description;
            label5.Text = weather.current_date;
            label8.Text = weather.current_time;
            label6.Text = weather.current_temp;
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            updateWeather();
        }
    }
}
