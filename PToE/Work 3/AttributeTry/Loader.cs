using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;

namespace AttributeTry
{
    [Source (URL = "http://csharpcorner.mindcrackerinc.netdna-cdn.com/article/round-image-in-xamarin-forms/Images/image005.jpg") ]
    class Loader
    {
        public int load()
        {

            var type = this.GetType();
            if(Attribute.IsDefined(type, typeof(Source)))
            {
                var source = Attribute.GetCustomAttribute(type, typeof(Source)) as Source;
                var name = source.URL.Substring(source.URL.LastIndexOf("/") + 1, source.URL.Length - source.URL.LastIndexOf("/")-1);

                Console.WriteLine("URL: {0}", source.URL);
                Console.WriteLine("Name: {0}", name);

                WebClient webClient = new WebClient();
                webClient.DownloadFile(source.URL, @"C:\Users\yuriy2\Documents\" + name);
            } 

            return 0;
        }
    }
}
