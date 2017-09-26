using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.IO;

namespace AttributeTry
{
    [Source (URL = "http://csharpcorner.mindcrackerinc.netdna-cdn.com/article/round-image-in-xamarin-forms/Images/image005.jpg") ]
    class Loader
    {
        public int load()
        {
            int size = 0;
            var type = this.GetType();
            if(Attribute.IsDefined(type, typeof(Source)))
            {
                var source = Attribute.GetCustomAttribute(type, typeof(Source)) as Source;
                var name = source.URL.Substring(source.URL.LastIndexOf("/") + 1, source.URL.Length - source.URL.LastIndexOf("/")-1);

                Console.WriteLine("URL: {0}", source.URL);

                WebClient webClient = new WebClient();
                webClient.Headers.Add("user-agent", "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.2; .NET CLR 1.0.3705;)");             

                byte[] file = webClient.DownloadData(source.URL);
                size = file.Length;

                try
                {
                    File.WriteAllBytes(@"D:\" + name, file);
                    Console.WriteLine("File saved to: {0}", @"D:\" + name);
                }
                catch (Exception e)
                {
                    Console.WriteLine("File saving failed: {0}", e.ToString());
                }

            } 

            return size;
        }
    }
}
