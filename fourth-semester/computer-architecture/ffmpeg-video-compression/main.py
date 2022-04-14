import ffmpeg

from functools import partial
from tkinter import filedialog
from tkinter import *


class Application:
    def __init__(self, master_app_):
        self.master_app = master_app_
        self.crf = 25
        self.buttons = {}
        self.labels = {}
        self.entries = {}
        self.frames = {}
        self.scales = {}

    def create_label(self, label_name_, master_, text_, row_, column_):
        label = Label(master_, text=text_)
        label.grid(row=row_, column=column_)
        self.labels[label_name_] = label

    def create_entry(self, entry_name_, master_, row_, column_):
        entry = Entry(master_)
        entry.grid(row=row_, column_=column_)
        self.entries[entry_name_] = entry

    def create_frame(self, frame_name_, master_, row_, column_):
        frame = Frame(master_)
        frame.grid(row=row_, column=column_)
        self.frames[frame_name_] = frame

    def create_button(self, button_name_, master_, text_, command_,
                      row_, column_):
        button = Button(master_, text=text_, command=command_)
        button.grid(row=row_, column=column_)
        self.buttons[button_name_] = button

    def get_open_file_path(self, entry_name_):
        file = filedialog.askopenfilename()
        self.entries[entry_name_].insert(0, file)

    def get_save_file_path(self, entry_name_):
        file = filedialog.asksaveasfilename()
        self.entries[entry_name_].insert(0, file)

    def create_scale(self, scale_name_, master_, from_val, to_val, orient_,
                     command_, row_, column_):
        scale = Scale(master_, from_=from_val, to=to_val, orient=orient_,
                      command=command_)
        scale.grid(row=row_, column=column_)
        self.scales[scale_name_] = scale

    def update_crf(self, value):
        self.crf = value

    def start(self):
        ffmpeg.input(self.entries["in_entry"].get()) \
            .output(self.entries["out_entry"].get(), crf=self.crf) \
            .run()
        info_label = Label(self.master_app,
                           text="CRF value: " + str(self.crf) + "\n" +
                                "Before compression\n" +
                                self.get_file_info("in_entry") + "\n" +
                                "After compression\n" +
                                self.get_file_info("out_entry"))
        info_label.pack(side="bottom")

    def get_file_info(self, entry_name_):
        info: dict = ffmpeg.probe(self.entries[entry_name_].get())
        size = str(round(int(info['format']['size']) / 1024, 2)) + " kb"
        bitrate = str(round(int(info['streams'][0]['bit_rate']) / 1024, 2)) + " kbps"
        return "Size: " + size + "\n" + \
               "Bitrate: " + bitrate


app_window = Tk()
app_window.title("Video compression")
app_window.geometry("320x240")
app_window.resizable(width=False, height=False)

application = Application(app_window)

global_frame = Frame(app_window)
global_frame.pack(side="top")

application.create_frame("in_out_frame", global_frame, 0, 0)
application.create_frame("in_frame", application.frames["in_out_frame"], 0, 0)
application.create_frame("out_frame", application.frames["in_out_frame"], 1, 0)

application.create_label("in_label", application.frames["in_frame"],
                         "Input file", 0, 0)
application.create_entry("in_entry", application.frames["in_frame"],
                         1, 0)
application.create_button("in_button", application.frames["in_frame"], "...",
                          partial(application.get_open_file_path, "in_entry"),
                          1, 1)

application.create_label("out_label", application.frames["out_frame"],
                         "Output file", 0, 0)
application.create_entry("out_entry", application.frames["out_frame"], 1, 0)
application.create_button("out_button", application.frames["out_frame"], "...",
                          partial(application.get_save_file_path, "out_entry"),
                          1, 1)

application.create_frame("start_frame", global_frame, 0, 1)
application.create_label("start_label", application.frames["start_frame"],
                         "Select CRF value: ", 0, 0)
application.create_scale("start_scale", application.frames["start_frame"],
                         25, 51, "horizontal", application.update_crf, 1, 0)
application.create_button("start_button", application.frames["start_frame"],
                          "Start", application.start, 2, 0)

app_window.mainloop()
