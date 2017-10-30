using System.Net;

namespace WeatherLoader
{
    public class Loader
    {
        public string apiUrl { get; set; }
        public string town { get; set; }
        public string appId { get; set; }

        public Loader()
        {
            apiUrl = "http://api.openweathermap.org/data/2.5/weather";
            town = "Kaliningrad";
            appId = "b52d72130fc650758b4ce9ff2dd3dd03";
        }

        public string load()
        {
            if (apiUrl.Length == 0)
                return "";

            string url = string.Format("{0}?q={1}&appid={2}&units=metric",apiUrl,town,appId);

            WebClient webClient = new WebClient();
            try
            {
                return webClient.DownloadString(url);
            }
            catch
            {
                return "";
            }
        }
    }
}
