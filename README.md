# 👾 So Long 🚀
Bu repo, 42 okulları müfredatının bir parçası olan so_long projesini içerir. MiniLibX grafik kütüphanesi kullanılarak C dilinde yazılmış basit bir 2D oyundur. Amacımız, haritadaki tüm toplanabilir öğeleri (💎) toplayıp çıkış kapısına (🚪) ulaşmak!
# 🎯 Oyunun Amacı
Oyundaki sevimli karakterimizi ( P ) kontrol ederek:

Haritadaki tüm koleksiyon öğelerini ( C - 💎 ) topla.
Tüm öğeler toplandıktan sonra çıkış kapısını ( E - 🚪 ) bul ve oraya ulaş.
Duvarlara ( 1 - 🧱 ) çarpmamaya dikkat et!
En az hamle ile oyunu bitirmeye çalış! 🏆
# ✅ Temel Özellikler
* 🗺️ Harita Okuma ve Doğrulama: .ber uzantılı harita dosyalarını okur ve kurallara uygunluğunu kontrol eder (dikdörtgen mi, duvarlarla çevrili mi, P, E, C elemanları doğru sayıda mı vb.).
* 🖼️ Grafiksel Gösterim: MiniLibX kütüphanesi ile oyun haritasını, karakteri, duvarları, toplanabilirleri ve çıkışı ekranda gösterir.
* 🕹️ Oyuncu Kontrolü: Klavye (W, A, S, D) ile oyuncu hareketlerini yönetir.
* 💎 Toplanabilirlik Mekanizması: Oyuncunun 'C' karakterlerinin üzerinden geçerek onları toplamasını sağlar.
* 🚪 Çıkış Mekanizması: Tüm 'C'ler toplandıktan sonra 'E' kapısını aktif hale getirir ve oyuncunun oyunu kazanmasını sağlar.
* 📊 Hamle Sayacı: Oyuncunun yaptığı hamle sayısını terminalde gösterir.
* 🎉 Başarılı Bitiş Ekranı: Oyun başarıyla tamamlandığında özel bir tebrik mesajı gösterir.
* ❌ Temiz Çıkış: ESC tuşu veya pencere kapatma butonu ile programı düzgün bir şekilde sonlandırır, ayrılan belleği serbest bırakır.
# 🗺️ Harita Formatı (.ber)
Oyun, .ber uzantılı dosyalarla tanımlanan haritaları kullanır. Haritalar şu kurallara uymalıdır:

1. Dikdörtgen Olmalı: Haritanın her satırı aynı uzunlukta olmalıdır.
2. Kapalı Olmalı: Haritanın etrafı tamamen duvarlarla ('1') çevrili olmalıdır.
3. Karakterler: Yalnızca şu karakterleri içerebilir:
+ 1: Duvar 🧱
+ 0: Boş Alan (Zemin) ⬜
+ C: Toplanabilir Öğe 💎
+ E: Çıkış Kapısı 🚪
+ P: Oyuncu Başlangıç Noktası 👾
4. Eleman sayıları:
+ Tam olarak bir tane 'P' (Oyuncu) olmalıdır.
+ Tam olarak bir tane 'E' (Çıkış) olmalıdır.
+ En az bir tane 'C' (Toplanabilir) olmalıdır.
5. Tüm toplanabilir eşyalar ulaşılabilir konumda olmalıdır:'C' lerin etrafı duvarla çevrili olmamalı.
## Örnek Geçerli Harita
```
11111111
1P0C00E1
10111001
10C100C1
11111111
```
# 📚 Bu Projede Pekiştirilen Beceriler
Bu proje, 42 müfredatı kapsamında aşağıdaki temel programlama ve problem çözme becerilerini pekiştirmeyi amaçlamaktadır:
+ 🖥️ Grafik Programlama (MiniLibX):  
➡️ Pencere yönetimi (oluşturma, kapatma).  
➡️Görsel (sprite) yükleme ve ekrana çizdirme (.xpm dosyaları).  
➡️Klavye ve pencere olaylarını (event) yönetme (tuş basımları, pencere kapanması, yeniden çizim).
+ 📄 Dosya Okuma ve İşleme:  
➡️Harita (.ber) dosyalarını açma, satır satır okuma (get_next_line).
+ 🧠 Algoritma ve Mantık:
➡️Harita doğrulama algoritmaları (duvar kontrolü, eleman sayısı ve türü kontrolü).  
➡️Oyuncu hareket mantığı ve basit çarpışma (duvar) kontrolü.  
➡️Oyun durumu yönetimi (toplanabilir sayımı, kazanma koşulu).
+ 💾 Bellek Yönetimi:  
➡️Dinamik bellek ayırma (malloc) ve serbest bırakma (free) (harita matrisi, MiniLibX nesneleri vb. için).  
➡️Bellek sızıntılarını önleme (özellikle exit_game fonksiyonunda).
+ 🧩 Modüler Programlama:  
➡️Kodun farklı işlevlere göre (src/ altındaki .c dosyaları) mantıksal olarak ayrılması.  
➡️Header dosyaları (.h) ile fonksiyon prototiplerinin ve yapı tanımlarının düzenlenmesi.


   
