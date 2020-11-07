#pragma once
namespace bafama
{
    template <typename T> class Noncopyable
    {
    protected:
        NonCopyable() = default;
        ~NonCopyable() = default;

    public:
        NonCopyable(const NonCopyable &) = delete;
        NonCopyable &operator=(const NonCopyable &) = delete;
        NonCopyable(const NonCopyable &&) = delete;
        NonCopyable &operator=(const NonCopyable &&) = delete;
    };
} // namespace bafama

