import psutil
import pygetwindow as gw
import win32gui
import win32process
import time

def get_active_window_title():
    try:
        active_window = gw.getActiveWindow()
        if active_window:
         return active_window.title
        else: "No active window found"
    except Exception as e:
        return f"Error: {e}"

def get_pid_from_active_window():
    hwnd = win32gui.GetForegroundWindow()  
    _, pid = win32process.GetWindowThreadProcessId(hwnd) 
    return pid

def get_app_name_from_pid(pid):
    try:
        return psutil.Process(pid).name()
    except psutil.NoSuchProcess:
        return "Process not found"
    except Exception as e:
        return f"Error: {e}"

def track_active_window():
    print("Tracking active window:")
    last_window = None

    try:
        while True:
            active_window_title = get_active_window_title()
            pid = get_pid_from_active_window()
            process_name = get_app_name_from_pid(pid)

            current_window = (active_window_title, process_name)
            
            if current_window != last_window:
                print(f"Active Window Title: {active_window_title}")
                print(f"Active Process ID: {pid}")
                print(f"Active Application Name: {process_name}")
                print("-----------------------------------------------------------")
                last_window = current_window

            time.sleep(1)
    except KeyboardInterrupt:
        print("\nStopped tracking.")

if __name__ == "__main__":
    track_active_window()
