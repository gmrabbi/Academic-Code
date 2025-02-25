# # # import kivy
# # # from kivy.app import App
# # # from kivy.uix.label import Label

# # # kivy.require('1.11.1')



# # # class MyFirstKivyApp(App):
# # # 	def build(self):
# # # 		return Label(text="Hello World !")


# # # MyFirstKivyApp().run()


# # # from kivy.app import App
# # # from kivy.uix.gridlayout import GridLayout
# # # from kivy.uix.label import Label
# # # from kivy.uix.textinput import TextInput

# # # class LoginScreen(GridLayout):

# # #     def __init__(self, **kwargs):
# # #         super(LoginScreen, self).__init__(**kwargs)
# # #         self.cols = 2
# # #         self.add_widget(Label(text='User Name'))
# # #         self.username = TextInput(multiline=False)
# # #         self.add_widget(self.username)
# # #         self.add_widget(Label(text='password'))
# # #         self.password = TextInput(password=True, multiline=False)
# # #         self.add_widget(self.password)


# # # class MyApp(App):

# # #     def build(self):
# # #         return LoginScreen()


# # # if __name__ == '__main__':
# # #     MyApp().run()
# # # ###################################################


# # import kivy
# # from kivy.app import App
# # from kivy.uix.label import Label
# # from kivy.uix.gridlayout import GridLayout
# # from kivy.uix.textinput import TextInput
# # from kivy.uix.button import Button
# # from kivy.uix.widget import Widget
# # from kivy.properties import ObjectProperty
# # from kivy.lang import Builder

# # Builder.load_file("kivy.kv")


# # class MyGrid(Widget):
# #     def press(self):
# #         pass
# #         # return Label(text="Hello World !")


# # class MyApp(App):  
# #     def build(self):
# #         return MyGrid()


# # if __name__ == "__main__":
# #     MyApp().run()


# from kivy.uix.button import Button
# from kivy.app import App
# from kivy.uix.boxlayout import BoxLayout
# from kivy.uix.label import Label
# from kivy.properties import NumericProperty


# class FontSizeApp(App):
#     font_size = NumericProperty(10)  # Initial font size

#     def increase_font_size(self):
#         if self.font_size < 40:
#             self.font_size += 5
#         else:
#             self.font_size = 5

#     def build(self):
#         layout = BoxLayout(orientation='vertical')
#         label = Label(text='Click the button to increase font size',
#                       font_size=self.font_size)
#         button = Label(text='Increase Font Size',
#                        on_touch_down=lambda instance, touch: self.increase_font_size())

#         layout.add_widget(label)
#         layout.add_widget(button)

#         return layout


# if __name__ == '__main__':
#     FontSizeApp().run()


# # /////////////////////////////


# class FontSizeApp(App):
#     font_size = NumericProperty(10)  # Initial font size

#     def increase_font_size(self, instance):
#         if self.font_size < 40:
#             self.font_size += 5
#         else:
#             self.font_size = 5

#     def build(self):
#         layout = BoxLayout(orientation='vertical')
#         label = Label(text='Font Size:', font_size=self.font_size)
#         button = Button(text='Increase Font Size')
#         # Bind the button press event to the function
#         button.bind(on_press=self.increase_font_size)

#         layout.add_widget(label)
#         layout.add_widget(button)

#         return layout


# if __name__ == '__main__':
#     FontSizeApp().run()


from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.properties import NumericProperty


class FontSizeApp(App):
    font_size = NumericProperty(10)  # Initial font size

    def increase_font_size(self, instance):
        if self.font_size < 40:
            self.font_size += 5
        else:
            self.font_size = 5

    def build(self):
        return BoxLayout()


if __name__ == '__main__':
    FontSizeApp().run()








