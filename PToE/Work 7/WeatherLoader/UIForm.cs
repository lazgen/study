using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WeatherLoader
{
    public partial class UIForm : Form
    {
        private IObservable m_observable = new WeatherUpdater();
        private IObserver m_openWeatherMapObserver;
        private IObserver m_apixuObserver;

        public UIForm()
        {
            m_openWeatherMapObserver = new OpenWeatherMapObserver(this);
            m_apixuObserver = new ApixuObserver(this);

            InitializeComponent();
            
            checkBoxApixu.Checked = true;
            checkBoxOWM.Checked = true;
            updInterval.Text = ((WeatherUpdater)m_observable).updateInterval.ToString();
            townTextBox.Text = ((WeatherUpdater)m_observable).updateTown;
        }

        public void updateOpenWeatherMapData(WeatherInfo info)
        {
            this.Invoke((MethodInvoker)(() =>
            {
                mainInfoOWM.Text = info.description;
                tempOWM.Text = info.temp;
                pressureOWM.Text = info.pressure;
                humidityOWM.Text = info.humidity;
                updTimeOWM.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
            }));
        }

        public void updateApixuData(WeatherInfo info)
        {
            this.Invoke((MethodInvoker)(() =>
            {
                mainInfoApixu.Text = info.description;
                tempApixu.Text = info.temp;
                pressureApixu.Text = info.pressure;
                humidityApixu.Text = info.humidity;
                updTimeApixu.Text = DateTime.Now.ToString("dd.MM.yyyy hh:mm");
            }));
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            ((WeatherUpdater)m_observable).updateInterval = double.Parse(updInterval.Text);
        }

        private void checkBoxOWM_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox checkBox = (CheckBox)sender;
            if (checkBox.Checked)
                m_observable.subscribe(m_openWeatherMapObserver);
            else
                m_observable.unsubscribe(m_openWeatherMapObserver);
            groupBox1.Enabled = checkBox.Checked;
        }

        private void checkBoxApixu_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox checkBox = (CheckBox)sender;
            if (checkBox.Checked)
                m_observable.subscribe(m_apixuObserver);
            else
                m_observable.unsubscribe(m_apixuObserver);
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
            ((WeatherUpdater)m_observable).updateTown = townTextBox.Text;
        }
    }
}
