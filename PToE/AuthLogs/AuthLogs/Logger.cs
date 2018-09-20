using System;
using System.IO;

namespace AuthLogs
{
    class Logger
    {
        private string logFile;

        public Logger(string logFile)
        {
            this.logFile = logFile;
        }

        public void RecordEntry(string entry)
        {
            using (StreamWriter writer = new StreamWriter(logFile, true))
            {
                writer.WriteLine(string.Format("[{0}] {1}",
                    DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss"), entry));
                writer.Flush();
            } 
        }
    }
}
