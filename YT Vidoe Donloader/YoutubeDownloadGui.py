import tkinter as tk
from tkinter import ttk, messagebox
import yt_dlp
import threading

# Function to update progress bar and show a completion message
def progress_hook(d):
    if d['status'] == 'downloading':
        pbar['value'] = d['_percent_str'].strip('%')
        root.update_idletasks()
    elif d['status'] == 'finished':
        pbar['value'] = 100
        messagebox.showinfo("Download Completed", "The video has been downloaded successfully!")
        pbar['value'] = 0

# Function to download video
def download_video():
    video_url = url_entry.get()

    ydl_opts = {
        'format': 'bestvideo+bestaudio/best',
        'outtmpl': '%(title)s.%(ext)s',
        'progress_hooks': [progress_hook],
    }

    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([video_url])

# Function to start download in a separate thread
def start_download():
    download_thread = threading.Thread(target=download_video)
    download_thread.start()

# Set up the main application window
root = tk.Tk()
root.title("YouTube Video Downloader")

# Create a label and entry for the YouTube URL
tk.Label(root, text="Enter YouTube URL:").pack(pady=10)
url_entry = tk.Entry(root, width=50)
url_entry.pack(pady=5)

# Create a button to start the download
download_button = tk.Button(root, text="OK", command=start_download)
download_button.pack(pady=10)

# Create a progress bar
pbar = ttk.Progressbar(root, orient="horizontal", length=300, mode="determinate")
pbar.pack(pady=20)

# Run the application
root.mainloop()
