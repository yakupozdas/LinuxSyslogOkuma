Syslog Linked List Projesi

Bu proje, Linux sistemlerinde syslog kayıtlarını okuyarak bağlı liste (linked list) veri yapısıyla saklamayı amaçlamaktadır. Syslog, sistem olaylarını ve hata kayıtlarını içeren önemli bir günlükleme mekanizmasıdır. Bu program, syslog dosyasını okur, her satırı bir düğüm olarak bağlı listeye ekler ve ekrana yazdırır.

Özellikler:

Linux sistemindeki /var/log/syslog dosyasını okur ve kayıtları işler.
Tek yönlü bağlı liste kullanarak kayıtları dinamik olarak bellekte saklar.
FIFO (First In, First Out) mantığıyla çalışarak en eski kayıt önce gösterilir.
Bellek yönetimi sağlanarak program sonunda kullanılan alan serbest bırakılır.
Kullanım:
Proje, bir C derleyicisi kullanılarak derlenmeli ve çalıştırılmalıdır. Syslog dosyasına erişim için root yetkisi gerekebilir.

Bu proje eğitim amaçlıdır ve gerçek sistemlerde dikkatli kullanılmalıdır.
