import pandas as pd

# weekday = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']

for d in pd.date_range(start='2023-01-23', end='2023-01-29', freq='D'):
    # print(weekday[d.weekday()])
    start = pd.to_datetime('9:00:00')
    end = pd.to_datetime('20:00:00')
    freq = pd.to_timedelta(60, 'minutes')
    while start < end:
        t, t2 = start, start + freq
        start += freq
        if (t <= pd.to_datetime('12:00:00') and t2 > pd.to_datetime('12:00:00')):
            continue
        if (t < pd.to_datetime('13:00:00') and t2 >= pd.to_datetime('13:00:00')):
            continue
        if (d.weekday() >= 5):
            continue
        print(f"{d.day_name()[:3]}. {t.hour:02}:{t.minute:02} - {t2.hour:02}:{t2.minute:02}")
