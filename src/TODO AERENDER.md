# in ffmpeg.cpp

- [ ] In encodeNextItem(), if is AE, launch AE render (ignore if ae not installed)  
    set output to temp EXR _done_  
    set output path _done_  
    launch audio process too  
    if ae render queue, just render project _done_
- [X] In finishedAE()  
    update currentitem to be the rendered frames, set as non ae and relaunch  
    or if render queue, go to next item
- [X] In readyReadAE() process aerender output
- [X] Implement multithreading (keep a 'QList<QProcess \*>')

# AE Installation

- [ ] Find the best way to install EXR output module

# in settingswidget.cpp

- [X] List installed AE (dropdown) with option for 'always use latest'
- [X] Custom aerender.exe path
- [X] Temp folder for ae render

# in main.cpp

- [X] Autodetect AE installation (latest) if set to always latest, or specified version

# Output widget

- [ ] No copy stream with aep
- [X] Disable everything if use ae render queue is checked

# Input Widget

- [X] add "Use Ae Render Queue" option

# Mainwindow

- [X] update stop button to stop aerender
