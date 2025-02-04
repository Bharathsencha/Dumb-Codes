import psutil  # For process management
import pygetwindow as gw  # For window management
import win32gui, win32process  # Windows API for GUI and process handling
import time  # For adding delays

# Retrieves the title of the currently active window
def get_active_window_title():
    try:
        active_window = gw.getActiveWindow()
        if active_window:
            return active_window.title  
        else:
            return "No active window found"
    except Exception as e:
        return f"Error: {e}"

# Retrieves the Process ID (PID) of the active window
def get_pid_from_active_window():
    hwnd = win32gui.GetForegroundWindow()
    _, pid = win32process.GetWindowThreadProcessId(hwnd)
    return pid

# Retrieves the application name using the PID
def get_app_name_from_pid(pid):
    try:
        return psutil.Process(pid).name()
    except psutil.NoSuchProcess:
        return "Process not found"
    except Exception as e:
        return f"Error: {e}"

# Continuously tracks the active window and its details
def track_active_window():
    print("Tracking active window:")
    last_window = None  # Stores last active window info to detect changes

    try:
        while True:
            active_window_title = get_active_window_title()
            pid = get_pid_from_active_window()
            process_name = get_app_name_from_pid(pid)
            
            current_window = (active_window_title, process_name)
            if current_window != last_window:  # Print only when window changes
                print(f"Active Window Title: {active_window_title}")
                print(f"Active Process ID: {pid}")
                print(f"Active Application Name: {process_name}")
                print("-----------------------------------------------------------")
                last_window = current_window

            time.sleep(1)
    except KeyboardInterrupt:
        print("\nStopped tracking.")

# Run the tracking function if executed directly
if __name__ == "__main__":
    track_active_window()
