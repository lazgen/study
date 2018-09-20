using System;
using System.Net.Mail;
using System.Net;

namespace AuthLogs
{
    class EmailSender
    {
        MailAddress from;
        MailAddress to;
        string fromPassword;

        public EmailSender(string from, string to, string fromPassword)
        {
            this.from = new MailAddress(from, "AuthLogs");
            this.to = new MailAddress(to);
            this.fromPassword = fromPassword;
        }

        public void SendEntry(string entry)
        {
            MailMessage message = new MailMessage(from, to);
            message.Subject = "Auth event";
            message.Body = string.Format("[{0}] {1}",
                        DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss"), entry);
            message.IsBodyHtml = false;

            SmtpClient smtp = new SmtpClient("smtp.tpu.ru", 25);

            smtp.EnableSsl = true;

            smtp.UseDefaultCredentials = false;

            smtp.Credentials = new NetworkCredential(from.Address, fromPassword);

            smtp.DeliveryMethod = SmtpDeliveryMethod.Network;

            smtp.Send(message);
        }
    }
}
