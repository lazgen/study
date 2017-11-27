using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WeatherLoader
{
    class Factory
    {
        private List<IFacade> m_services = new List<IFacade>();
        private List<string> m_names = new List<string>();

        public Factory()
        {
            IFacade openweathermap = new Facade();
            IFacade apixu = new Facade1();

            m_services.Add(openweathermap);
            m_services.Add(apixu);

            m_names.Add("Open Weather Map");
            m_names.Add("Apixu");
        }

        public List<string> services()
        {
            return m_names;
        }

        public IFacade getService(int index)
        {
            return m_services[index];
        }
    }
}
