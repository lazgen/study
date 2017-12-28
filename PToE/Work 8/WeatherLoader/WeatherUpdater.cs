using System.Timers;

namespace WeatherLoader
{
    class WeatherUpdater
    {
        public delegate void WeatherInfoDelegate(WeatherInfo weatherInfo);

        public event WeatherInfoDelegate WeatherInfoLoaded;

        private Factory m_factory = new Factory();
        private Timer m_timer = new Timer();
        private string m_town = "Tomsk";

        public WeatherUpdater()
        {
            m_timer.Interval = 10000;
            m_timer.Elapsed += timer_Elapsed;
            m_timer.AutoReset = true;
            m_timer.Start();
        }

        public double updateInterval
        {
            get { return m_timer.Interval; }
            set { m_timer.Interval = value; }
        }

        public string updateTown
        {
            get { return m_town; }
            set { m_town = value; }
        }

        private void timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            updateWeaterInfo();
        }

        private void updateWeaterInfo()
        {
            foreach(string service in m_factory.services())
            {
                WeatherInfo data = m_factory.getServiceByName(service).updateWeatherInfo(m_town);
                data.service = service;
                if (WeatherInfoLoaded != null)
                    WeatherInfoLoaded(data);
            }
        }
    }
}
