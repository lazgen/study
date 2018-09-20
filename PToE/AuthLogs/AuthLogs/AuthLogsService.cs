using System;
using System.ServiceProcess;


namespace AuthLogs
{
    public partial class AuthLogsService : ServiceBase
    {
        Logger logger;
        EmailSender email;

        public AuthLogsService()
        {
            InitializeComponent();
            this.CanStop = true;
            this.CanPauseAndContinue = true;
            this.AutoLog = true;
            this.CanHandleSessionChangeEvent = true;
        }

        protected override void OnStart(string[] args)
        {
            email = new EmailSender("sergey7@tpu.ru", "sergeichernykh95@gmail.com", "Hswfhm_Cdtnf1995");
            logger = new Logger("C:\\authlog.txt");
        }

        protected override void OnStop()
        {
        }

        protected override void OnSessionChange(SessionChangeDescription changeDescription)
        {
            string entry = string.Empty;

            switch(changeDescription.Reason)
            {
                case SessionChangeReason.SessionLogon:
                    entry = string.Format("The user has logged on");
                    break;
                case SessionChangeReason.SessionLogoff:
                    entry = string.Format("The user has logged out");
                    break;
                case SessionChangeReason.SessionLock:
                    entry = string.Format("The user has locked the system");
                    break;
                case SessionChangeReason.SessionUnlock:
                    entry = string.Format("The user has unlocked the system");
                    break;
                default:
                    entry = string.Format("Session change notice received: {0}", changeDescription.Reason.ToString());
                    break;
            }

            logger.RecordEntry(entry);

            try
            {
                email.SendEntry(entry);
            }
            catch (Exception ex)
            {
                logger.RecordEntry(string.Format("Error sending email: {0}", ex.ToString()));
            }
        }
    }
}
