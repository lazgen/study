using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WeatherLoader
{
    class Factory
    {
        private IFacade openweathermap = new Facade();
        private IFacade apixu = new Facade1();

        public IFacade getOpenweathermap()
        {
            return openweathermap;
        }

        public IFacade getApixu()
        {
            return apixu;
        }
    }
}
