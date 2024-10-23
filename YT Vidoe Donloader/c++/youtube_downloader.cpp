#include <iostream>
#include <cstdlib> // for system()
#include <string>

void download_video(const std::string& url) {
    // Command to download the video using yt-dlp
    std::string ytdlp_command = "yt-dlp -f \"bestvideo[height<=1080]+bestaudio/best[height<=1080]\" --merge-output-format mp4 \"" + url + "\"";
    
    // Execute the download command
    int result = system(ytdlp_command.c_str());

    // Check if the command was successful
    if (result == 0) {
        std::cout << "Download completed!" << std::endl;
    } else {
        std::cout << "An error occurred during download." << std::endl;
    }
}

int main() {
    // Sample video link to download
    std::string video_url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ"; // Replace with your desired video URL

    // Call the download_video function with the sample video URL
    download_video(video_url);

    return 0;
}
