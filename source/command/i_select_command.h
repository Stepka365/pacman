#pragma once

class ISelectCommand {
public:
    virtual void execute() = 0;
    virtual ~ISelectCommand() = default;
};