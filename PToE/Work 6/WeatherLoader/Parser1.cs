using Newtonsoft.Json.Linq;

namespace WeatherLoader
{
    class Parser1
    {
        public WeatherInfo parse(string info)
        {
            if (info.Length == 0)
                return new WeatherInfo();

            WeatherInfo weather = new WeatherInfo();

            JObject o = JObject.Parse(info);

            weather.town = (string)o["location"]["name"];
            weather.temp = (string)o["current"]["temp_c"];
            weather.pressure = (string)o["current"]["pressure_mb"];
            weather.humidity = (string)o["current"]["humidity"];
            weather.description = (string)o["current"]["condition"]["text"];

            return weather;
        }
    }
}
