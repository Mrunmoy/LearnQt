# Create an IP Address Input Text Widget
Project created using QT Creator Community Edition

# WIP

This Widget has four QLineEdit boxes. Each QLineEdit box has it's own QIntValidator set to 
```
QIntValidator(1, 255, nullptr);
```
so as to restring valid values to be between 1 annd 255.

And listen to QLineEdit's following signals:
- `editingFinished`
- `inputRejected`
- `returnPressed`


# Issue:
1. The validation doesn't hit when typing any number within <=3 digits. It only hits when the fourth digit is typed/ Enter is pressed and restrict it to 3 digits per QLineEdit box.
2. When 0s are typed, it lets you enter as many 0s as you can


# Thoughts:
Probbaly needs to handle QLineEdt's `textEdited` or `textChanged` signal and validate the text manually.
Also need to think about how to handle changing focus from one box to next and validate

# TODO:
- A way to signal from this widget to it's creator that all fields are valid
- A way for it's creator to fill in values
