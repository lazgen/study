using System.Net;

namespace WeatherLoader
{
    public class Loader
    {
        public string url { get; set; }

        public Loader()
        {
            url = "http://termo.tomsk.ru/data.json";
        }

        public Loader(string _url)
        {
            url = _url;
        }

        public string load()
        {
            if (url.Length == 0)
                return "";

            WebClient webClient = new WebClient();
            return webClient.DownloadString(url);
        }
    }
}
