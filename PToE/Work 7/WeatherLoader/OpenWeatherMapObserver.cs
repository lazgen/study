using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WeatherLoader
{
    class OpenWeatherMapObserver : IObserver
    {
        private UIForm m_form;
        private string m_objectName;

        public OpenWeatherMapObserver(UIForm form)
        {
            m_form = form;
            m_objectName = "Open Weather Map";
        }

        public void update(WeatherInfo info)
        {
            if (m_form != null)
            {
                m_form.updateOpenWeatherMapData(info);
            }
        }

        public string objectName
        {
            get { return m_objectName; }
            set { m_objectName = value; }
        }
    }
}
