using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WeatherLoader
{
    class ApixuObserver : IObserver
    {
        private UIForm m_form;
        private string m_objectName;
        
        public ApixuObserver(UIForm form)
        {
            m_form = form;
            m_objectName = "Apixu";
        }

        public void update(WeatherInfo info)
        {
            if(m_form != null)
            {
                m_form.updateApixuData(info);
            }
        }

        public string objectName
        {
            get { return m_objectName; }
            set { m_objectName = value; }
        }
    }
}
