// sort_three: A стекийн эхний 3 элементийг эрэмбэлэх (хамгийн ихдээ 3 үйлдэл, ихэнхдээ ≤2)
// Индекс ашигладаг тул 0 = хамгийн бага, 2 = хамгийн их байх ёстой эцэст (0 дээр, 1, 2 доор)
// Энэ функц 42-ийн олон төсөлд (жишээ нь nschumac, aguncarr гэх мэт) ашиглагддаг хамгийн оновчтой хувилбар
static void sort_three(t_stacks *s)
{
    int a = s->a[0];
    int b = s->a[1];
    int c = s->a[2];

    // Хамгийн их (max) дээр байвал rotate эсвэл swap хийж доош нь оруулна
    if (a > b && a > c)                  // top нь max
    {
        ra(s);                           // max доошилно → b эсвэл c дээр ирнэ
        // Дараа нь үлдсэн 2-ыг шалгана
        if (s->a[0] > s->a[1])
            sa(s);
    }
    else if (b > c)                      // mid эсвэл bot нь max (top биш)
    {
        rra(s);                          // max дээр гаргана
        if (s->a[0] > s->a[1])
            sa(s);
    }
    else if (b > a)                      // Зөвхөн mid > top (bot нь хамгийн бага)
    {
        sa(s);                           // mid болон top солих
    }
    // Бусад тохиолдолд (c > a && c > b гэх мэт) аль хэдийн эрэмбэлэгдсэн эсвэл дээрх кейсээр шийдэгдэнэ
}
static void sort_three(t_stacks *s)
{
    // Хэрвээ top > mid бол sa хийж эхэлнэ (ихэнх муу кейсийг шийднэ)
    if (s->a[0] > s->a[1])
    {
        if (s->a[1] > s->a[2])       // top > mid > bot → sa + rra
        {
            sa(s);
            rra(s);
        }
        else if (s->a[0] > s->a[2])  // top > bot, mid жижиг эсвэл том
            sa(s);                   // зөвхөн sa
        else
            ra(s);                   // top > mid биш, гэхдээ top > bot биш → ra
    }
    else
    {
        // top ≤ mid
        if (s->a[0] > s->a[2])       // top > bot → rra
            rra(s);
        else if (s->a[1] > s->a[2])   // mid > bot → rra + sa
        {
            rra(s);
            sa(s);
        }
        // Бусад тохиолдолд аль хэдийн sorted
    }
}