 ++++[>++++[>+++<-]<-]   writes 48 / 0x30 / '0' in cell(2)
    ,>,>                    reads two numbers in cell(0) and cell(1)
    [<-<->>-]               decremens cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      gets to cell(0)
    [                       multiplication loop
        >                   gets to cell(1)
        [>+>+<<-]           moving cell(1) to cell(2) and cell(3)
        >>                  gets the cell(3)
        [<<+>>-]            moving cell(3) back to cell(1)
        <<<-                decrements the cell(0)
    ]
    >[-]<                   setting cell(1) to 0 so that it can be used as counter (we are in cell 0 here)
    ++++[>++++[>+++<-]<-]   adds 48 / 0x30 / '0' to cell(2) cell 2 has the result
    >>.                     prints result (go to cell 2 and print)
