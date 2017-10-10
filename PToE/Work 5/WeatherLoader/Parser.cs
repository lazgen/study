using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using System.Runtime.Serialization;

namespace WeatherLoader
{
    class Parser
    {
        public WeatherInfo parse(string info)
        {

            //DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(WeatherInfo));
            WeatherInfo weather = (WeatherInfo)serializer.ReadObject(info);

            return new WeatherInfo();
        }
    }
}
