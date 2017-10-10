using System;
using System.Net;
using System.IO;

namespace WeatherLoader
{
    public class Loader
    {
        public string load(string url)
        {
            if (url.Length == 0)
                return "";

            WebClient webClient = new WebClient();
            return webClient.DownloadString(url);
        }
    }
}
