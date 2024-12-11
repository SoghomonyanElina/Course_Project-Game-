#include <iostream>
#include <memory>

//Command
class Command {
  public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

//Receiver
class TV {
  public:
    void turnOn() {
        std::cout << "TV is ON" << std::endl;
    }
    void turnOff() {
        std::cout << "TV is OFF" << std::endl;
    }
    void changeChannel(int channel) {
        std::cout << "Channel changed to " << channel << std::endl;
    }
    void adjustVolume(int level) {
        std::cout << "Volume adjusted to " << level << std::endl;
    }
};

//ConcreteCommand
class TurnOnTVCommand : public Command {
  private:
    std::shared_ptr<TV> tv_;
  public:
    TurnOnTVCommand(std::shared_ptr<TV> tv) : tv_(tv) {}
    void execute() override {
        tv_->turnOn();
    }
};

class TurnOffTVCommand : public Command {
  private:
    std::shared_ptr<TV> tv_;
  public:
    TurnOffTVCommand(std::shared_ptr<TV> tv) : tv_(tv) {}
    void execute() override {
        tv_->turnOff();
    }
};

class ChangeChannelCommand : public Command {
  private:
    std::shared_ptr<TV> tv_;
    int channel;
  public:
    ChangeChannelCommand(std::shared_ptr<TV> tv, int channel) : tv_(tv), channel(channel) {}
    void execute() override {
        tv_->changeChannel(channel);
    }
};

class AdjustVolumeCommand : public Command {
  private:
    std::shared_ptr<TV> tv_;
    int volume;
  public:
    AdjustVolumeCommand(std::shared_ptr<TV> tv, int volume) : tv_(tv), volume(volume) {}
    void execute() override {
        tv_->adjustVolume(volume);
    }
};

//Invoker
class RemoteControl {
  public:
    void executeCommand(std::unique_ptr<Command> cmd) {
        cmd->execute();
    }
};

int main() {
    auto tv = std::make_shared<TV>();
    auto turnOn = std::make_unique<TurnOnTVCommand>(tv);
    auto turnOff = std::make_unique<TurnOffTVCommand>(tv);
    auto changeChannel = std::make_unique<ChangeChannelCommand>(tv, 5);
    auto adjustVolume = std::make_unique<AdjustVolumeCommand>(tv, 10);
    RemoteControl remote;
    remote.executeCommand(std::move(turnOn));
    remote.executeCommand(std::move(changeChannel));
    remote.executeCommand(std::move(adjustVolume));
    remote.executeCommand(std::move(turnOff));
}





