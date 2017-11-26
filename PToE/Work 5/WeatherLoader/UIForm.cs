using System;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class UIForm : Form
    {
        IFacade facade = new Facade();

        public UIForm()
        {
            InitializeComponent();
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            facade.updateWeatherInfo(textBox1.Text);

            textBox1.Text = facade.weatherInfo.town;
            label4.Text = facade.weatherInfo.description;
            label6.Text = facade.weatherInfo.temp;
            label8.Text = facade.weatherInfo.pressure;
            label10.Text = facade.weatherInfo.humidity;
            label5.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
        }
    }
}
