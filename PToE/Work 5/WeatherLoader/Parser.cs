using System;
using System.Web.Script.Serialization;

namespace WeatherLoader
{
    class Parser
    {
        public WeatherInfo parse(string info)
        {
            WeatherInfo weather = new JavaScriptSerializer().Deserialize<WeatherInfo>(info);
            return weather;
        }
    }
}
