# qt_text_converter_gui_template

The simpliest GUI template code for text converters tests.

## GUI
Two plain text panels (for input and output text) and two buttons (one for starting converting, another one has user-defined action).

## CLI Arguments
Two possible command line arguments:
-t <Default Text>;
-f <Default Text file>;

## Using
Main form's class interface has 1 signal and 1 slot connecting to those you can do all the work. 
`signals:
    void SendLeftPanelText(const QString&);
public slots:
    void ReceiveRightPanelText(const QString&);`

In addition to that interface you can use signal `void UserAction()` to connect some of your internal procedures.

There are demonstration code with mediator class in sources. Mediator performs connections of SendLeftPanelText signal straight to the ReceiveRightPanelText slot.
UserAction signal connects to lambda that performs message box showing. Feel free to change it.

## Tests
Tested on MSYS2 (MinGW64).
