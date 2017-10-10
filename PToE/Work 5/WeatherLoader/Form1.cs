using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Globalization;

namespace WeatherLoader
{
    public partial class Facade : Form
    {
        
        public Facade()
        {
            InitializeComponent();
        }

        private void updateButton_Click(object sender, EventArgs e)
        {
            updateWeather();
        }

        private void updateWeather()
        {
            DateTime localDate = DateTime.Now;
            label5.Text = localDate.ToString();
            Loader l = new Loader();
            label6.Text = l.load();
        }
    }
}
