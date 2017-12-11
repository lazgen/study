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
            IFacade openweathermap = new FacadeA();
            IFacade apixu = new FacadeB();

            m_services.Add(openweathermap);
            m_services.Add(apixu);

            m_names.Add("Open Weather Map");
            m_names.Add("Apixu");
        }

        public List<string> services()
        {
            return m_names;
        }

        public IFacade getServiceByInd(int index)
        {
            if (index < 0 || index >= m_services.Count)
                return null;

            return m_services[index];
        }

        public IFacade getServiceByName(string name)
        {
            int ind = m_names.IndexOf(name);
            return getServiceByInd(ind);
        }
    }
}
