#qtsnowloadcount<br>
<br>
c++-based qt for android(necessitas) wizard gui example with serialization and with sendsms<br>
This project loves to open by default into the desktop target.  In order to target the android project,
you need to click on the projects button in the left pane of the qtcreator IDE.<br>  
Then select the android armv7 target.<br>
Then click the configure button.<br>
Then rebuild project.<br>
Then Deploy and run.<br>
<br>
If your android is connected to your computer, then the deploy and run will automagically happen onto your android phone.<br>
If the SendSMS doesn't work, it's because the AndroidManifest.xml permissions have not been generated properly<br>
into the apk file.<br>
Modify the AndroidManifest.xml file outside of the qtcreator ide, then ndk_build then ant dist/debug.<br>
<br>
#ENVIRONMENT VARIABLES TO FOR BUILDING OUTSIDE OF QTCREATOR IDE<br>
<br>
<code>
export NDKROOT=/opt/NecessitasQtSDK/android-ndk<br>
export ANDROID_NDK_ROOT=/opt/NecessitasQtSDK/android-ndk<br>
export ANDROID_HOME=/opt/android-sdk-r22.3<br>
alias qt520creator=/opt/Qt5.2.0/Tools/QtCreator/bin/qtcreator<br>
cd qtsnowloadcount/<br>
</code>
<br>
the original project was called snowloadcount.<br>
I decided to rename it to qtsnowloadcount considering I made different guis gtk and qt.<br>
<code>
rm snowloadcount.pro.user*<br>
mv snowloadcount.pro qtsnowloadcount.pro <br>
</code>

I configure project again for armv7<br>
rebuild all project<br>
but it complains about an error<br>
<code>
cd build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/<br>
make install INSTALL_ROOT=/home/loongson/build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/android-build<br>
</code>
<br>
rebuild all project<br>
cpp rebuild succeeds now to the android stuff<br>
android redeploy project<br>
installs ok, but permissions(android.permissions.SEND_SMS missing) exceptions crash the app<br>
the permissions were added but they don't get moved to the build directory's AndroidManifest<br>
so we have to edit these AndroidManifest.xml files ourselves and then ant debug/install ourselves.<br>
<code>
cd qtsnowloadcount/<br>
find ../qtsnowloadcount/ -name "AndroidManifest.xml" -print|etags -<br>
find ../build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/ -name "AndroidManifest.xml" -print|xargs etags -a<br>
</code>
tags-search "android.permission" and add the SEND_SMS permission and the permission exception won't crash the app on the phone and the sms will get sent.<br>
<code>
cd /home/loongson/build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/<br>
cd android-build/<br>
ant debug<br>
$ANDROID_HOME/platform-tools/adb -d install bin/QtApp-debug.apk <br>
</code>
that's it.<br>
<br>
#BUILD CYCLE<br>
<br>
Here is my build cycle outside of qtcreator as much as possible:<br>
Step 1)start qtcreator, create the project<br>
Step 2)from the qtcreator ide, rebuild the project for the first time<br>
Step 3)exit qtcreator ide<br>
<br>
Step 4)<br>
edit some .cpp/.h files in /home/loongson/qtsnowloadcount<br>
<br>
Step 5)<br>
<code>
cd /home/loongson/build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/<br>
</code>
<br>
Step 6) build the .cpp/h files into a .so file<br>
<code>
make<br>
</code>
<br>
Step 7) move the .so file into the android build directory<br>
<code>
make install INSTALL_ROOT=/home/loongson/build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/android-build<br>
</code>
<br>
Step 8)now make the android install package file .apk<br>
<code>
cd /home/loongson/build-qtsnowloadcount-Android_for_armeabi_GCC_4_8_Qt_5_2_0-Debug/android-build/<br>
ant debug<br>
</code>
<br>
Step 9)now install the android package onto the phone<br>
<code>
$ANDROID_HOME/platform-tools/adb -d install bin/QtApp-debug.apk<br>
</code>
<br>
Cycle back to Step 4)<br>
If your app crashes on the phone then run the app from qtcreator ide to see the debug messages from the ide application console.<br>
<br>
#WITHOUT QT CREATOR<br>
<code>
export ANDROID_NDK_ROOT=/opt/android-ndk-r9c<br>
export NDKROOT=/opt/android-ndk-r9c<br>
export ANDROID_HOME=/opt/android-sdk-r22.3<br>
/opt/Qt5.2.0/Tools/QtCreator/bin/qtcreator<br>
cd $NDKROOT/samples/native-activity/<br>
$ANDROID_HOME/tools/android update project -p . --target 26 --name native-activity<br>
$NDKROOT/ndk-build V=1 -B<br>
ant debug<br>
$ANDROID_HOME/platform-tools/adb -d install $NDKROOT/samples/native-activity/bin/native-activity-debug.apk<br>
alias qt520creator=/opt/Qt5.2.0/Tools/QtCreator/bin/qtcreator<br>
</code>
