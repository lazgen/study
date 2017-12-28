using System;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class UIForm : Form
    {
        private WeatherUpdater m_weatherUpdater = new WeatherUpdater();
        public UIForm()
        {
            InitializeComponent();
            
            checkBoxApixu.Checked = true;
            checkBoxOWM.Checked = true;
            updInterval.Text = m_weatherUpdater.updateInterval.ToString();
            townTextBox.Text = m_weatherUpdater.updateTown;
        }

        public void updateOpenWeatherMapData(WeatherInfo info)
        {
            this.Invoke((MethodInvoker)(() =>
            {
                if (info.service == "Open Weather Map")
                {
                    mainInfoOWM.Text = info.description;
                    tempOWM.Text = info.temp;
                    pressureOWM.Text = info.pressure;
                    humidityOWM.Text = info.humidity;
                    updTimeOWM.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
                }
            }));
        }

        public void updateApixuData(WeatherInfo info)
        {
            this.Invoke((MethodInvoker)(() =>
            {
                if (info.service == "Apixu")
                {
                    mainInfoApixu.Text = info.description;
                    tempApixu.Text = info.temp;
                    pressureApixu.Text = info.pressure;
                    humidityApixu.Text = info.humidity;
                    updTimeApixu.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
                }
            }));
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            m_weatherUpdater.updateInterval = double.Parse(updInterval.Text);
        }

        private void checkBoxOWM_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox checkBox = (CheckBox)sender;
            if (checkBox.Checked)
                m_weatherUpdater.WeatherInfoLoaded += updateOpenWeatherMapData;
            else
                m_weatherUpdater.WeatherInfoLoaded -= updateOpenWeatherMapData;
            groupBox1.Enabled = checkBox.Checked;
        }

        private void checkBoxApixu_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox checkBox = (CheckBox)sender;
            if (checkBox.Checked)
                m_weatherUpdater.WeatherInfoLoaded += updateApixuData;
            else
                m_weatherUpdater.WeatherInfoLoaded -= updateApixuData;
            groupBox2.Enabled = checkBox.Checked;
        }

        private void updInterval_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
                e.Handled = true;
            if (e.KeyChar == (char)8)
                e.Handled = false;
            if (e.KeyChar == (char)13)
                updateButton_Click(sender, e);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            m_weatherUpdater.updateTown = townTextBox.Text;
        }
    }
}
