#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048  // Define maximum length for URL

void download_video(const char *url) {
    char command[MAX_URL_LENGTH + 128]; // Buffer for the command string

    // Construct the yt-dlp command
    snprintf(command, sizeof(command),
             "yt-dlp -f \"bestvideo[height<=1080]+bestaudio/best[height<=1080]\" --merge-output-format mp4 \"%s\"", url);

    /**
     * - The buffer size is set to `MAX_URL_LENGTH + 128` to account for the URL and the additional text in the yt-dlp command.
     * - MAX_URL_LENGTH (2048) is chosen to accommodate long URLs, which are common with query parameters.
     * - The yt-dlp command syntax adds about 100–120 extra characters, including format options and output specifications.
     * - Using `snprintf` ensures the command string is safely constructed without overflowing the buffer.
     * - If the URL or command exceeds the buffer size, `snprintf` will truncate it, avoiding memory issues.
     * Example:
       Consider the following scenario:
       URL: "https://www.youtube.com/watch?v=dHUq9xJcaZs&param1=value1&param2=value2"
       Command syntax: yt-dlp -f "bestvideo[height<=1080]+bestaudio/best[height<=1080]" --merge-output-format mp4

       The total command length could be:

       URL: 150 characters
       Command syntax: ~110 characters
       Total: 260 characters
       By setting a buffer size of MAX_URL_LENGTH + 128, the program can handle even longer URLs and complex commands 
       without risking buffer overflow
     */

    // Execute the command
    int result = system(command);

    // Check if the command was successful
    if (result == 0) {
        printf("Download completed successfully!\n");
    } else {
        printf("An error occurred during the download.\n");
    }
}

int main() {
    char video_url[MAX_URL_LENGTH];

    // Prompt the user for a video URL
    printf("Enter the video URL: ");
    if (fgets(video_url, sizeof(video_url), stdin) != NULL) {
        // Remove the newline character from the input
        size_t len = strlen(video_url);
        if (len > 0 && video_url[len - 1] == '\n') {
            video_url[len - 1] = '\0';
        }

        // Call the download function with the provided URL
        download_video(video_url);
    } else {
        printf("Failed to read input.\n");
    }

    return 0;
}
