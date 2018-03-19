# Nesne Tabanli Programlama I - Donem Projesi
#### Gezgin Robot Denetim Sistemi


### Grup 18

  - Ali Emir Şen - 152120141101
  - İkbal Tayyar Yazıcı - 152120141072
  - Sinan Dirican - 152120131027
  - Gizem Taşçı - 152120131100
  - Necdet Özen -  152120141077

### Proje Hakkinda

> Robot kontrol uygulamasi.
> Kontrol uygulamasi ve iletisim arayuzu Aria kutuphanesi yardimiyla C++ ile yapilmistir.
> MobileSim Robot Simulator uzerinde, proje icin verilen ofis ortaminda test edilmistir.

### Gorev Paylasimi

| Class | Blame |
| ------ | ------ |
| PioneerRobotAPI | Metin Ozkan |
| RobotInterface | Ikbal Tayyar Yazici & Ali Emir Sen |
| PioneerRobotInterface | Ikbal Tayyar Yazici & Ali Emir Sen |
| RobotControl | Ikbal Tayyar Yazici & Ali Emir Sen |
| RangeSensor | Gizem Tasci & Necdet Ozen |
| Position | Gizem Tasci & Sinan Dirican |
| LaserSensor | Necdet Ozen & Sinan Dirican |
| SonarSensor | Necdet Ozen & Sinan Dirican |
| Direction (enum) | Metin Ozkan |
| Refactor | Ali Emir Sen & Gizem Tasci |
| Compile & Test | Ikbal Tayyar Yazici & Gizem Tasci |

### Menu Tasarimi

```sh
Main Menu
1. Connection
2. Motion
3. Sensor
4. Quit
```
```sh
Connection Menu
1. Connect Robot
2. Disconnect Robot
3. Back
```
```sh
Motion Menu
1. Move Robot
2. Turn Left
3. Turn Right
4. Forward
5. Stop
6. Move Distance
7. Close Wall
8. Back
```

### Gelistirme Fikirleri

Proje uzerine eklenebilecek yeni ozellikler uzerine, grubumuzun fikirleri:

 - Ortami haritalama ve sonraki kullanimlar icin saklama.
 - Sensorleri kullanarak objeleri tanimlama ve bilgilerini saklama.
 - Birden fazla robot kullanimi icin uygulamanin optimizasyonu ve robotlar arasi haberlesme icin kullanimi.


 