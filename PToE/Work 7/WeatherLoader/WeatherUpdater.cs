using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace WeatherLoader
{
    class WeatherUpdater : IObservable
    {
        private Factory m_factory = new Factory();
        private List<IObserver> m_observers = new List<IObserver>();
        private Timer m_timer = new Timer();
        private string m_town = "Tomsk";

        public WeatherUpdater()
        {
            m_timer.Interval = 10000;
            m_timer.Elapsed += timer_Elapsed;
            m_timer.AutoReset = true;
            m_timer.Start();
        }

        public void subscribe(IObserver obs)
        {
            if (!m_observers.Contains(obs))
                m_observers.Add(obs);
        }

        public void unsubscribe(IObserver obs)
        {
            if (m_observers.Contains(obs))
                m_observers.Remove(obs);
        }

        public void notify(IObserver observer, WeatherInfo data)
        {
            throw new NotImplementedException();
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
                foreach (var observer in m_observers)
                {
                    if (observer.objectName == service)
                    {
                        observer.update(data);
                    }
                }
            }
        }
    }
}
