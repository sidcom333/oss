import os
import multiprocessing

def child_process():
    print(f"child created: pid: {os.getpid()} parent: {os.getppid()}")

if __name__ == "__main__":
    print(f"pid: {os.getpid()} parent: {os.getppid()}")

    # Create a child process
    child = multiprocessing.Process(target=child_process)
    child.start()
    child.join()

    # Code executed by the parent process
    print(f"parent after fork pid: {os.getpid()} child pid: {child.pid}")
