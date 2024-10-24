Firts Download VLC as it can open.webm files 

https://www.videolan.org/vlc/

Then Download yt-dlp using "pip install yt-dlp" (paste this in terminal in vs code or in Command Prompt in Windows)

If already installed update using same command : pip install yt-dlp

Dowload python 

You can verify using "yt-dlp --version" for yt-dlp library

Paste the video url in : video_url = 'You_Video_URL' and run the code

Open the video using VLC for audio to work 

It willl download videos at its best quality possible so 

Downloading FFMPEG is important it helps to merge audio and video files together 

Here’s a step-by-step guide to installing ffmpeg on Windows:

Step 1: Download ffmpeg

Go to the official FFmpeg download page.

Under the "Get packages & executable files" section, click on Windows.

Choose a build. One popular choice is from gyan.dev: 
(direct link : https://www.gyan.dev/ffmpeg/builds/)

Visit the FFmpeg Windows builds by Gyan.

Scroll down to "Release builds" and download the "ffmpeg-git-full.7z" file (or ZIP if you prefer).

Step 2: 
Extract the Files

Once downloaded, extract the .7z or .zip file using an extraction tool like 7-Zip or WinRAR.
Reccomend to save file in other dives and not on C incase your OS gets corrupted you dont have to re-install it over and over again
You’ll now have a folder containing the extracted files.

Inside the extracted folder, locate the bin directory. This contains the ffmpeg.exe and other executables needed to run FFmpeg.

Step 3:
Add FFmpeg to System PATH

This step allows you to run ffmpeg from any folder in the Command Prompt or PowerShell without having to navigate to the bin folder every time.

Copy the path to the bin folder

to confirm installation : ffmpeg -version


