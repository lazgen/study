using System.Net;

namespace WeatherLoader
{
    public class Loader1
    {
        public string apiUrl { get; set; }
        public string town { get; set; }
        public string appId { get; set; }

        public Loader1()
        {
            apiUrl = "http://api.apixu.com/v1/current.json";
            town = "Kaliningrad";
            appId = "00cdf3eec9484762be2204702172611";
        }

        public string load()
        {
            if (apiUrl.Length == 0)
                return "";

            string url = string.Format("{0}?key={1}&q={2}", apiUrl, appId, town);

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
