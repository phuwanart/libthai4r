#include<ruby.h>
#include<thai/thbrk.h>
#include<thai/thstr.h>

VALUE mLibThai;

extern int th_istis(thchar_t c);

static VALUE
f_th_brk(VALUE obj,VALUE v_str)
{
  int* pos = ALLOC_N(int, RSTRING_LEN(v_str));
  int n, i;
  VALUE a;
  n = th_brk((thchar_t *)RSTRING_PTR(v_str), pos, RSTRING_LEN(v_str));
  a = rb_ary_new2(n);
  for(i = 0;i < n; i++)
    {
      rb_ary_push(a, INT2FIX(pos[i]));
    }
  free(pos);
  return a;
}

static VALUE
f_th_brk_line(int argc,VALUE *argv,VALUE obj)
{
  char *cut_code;
  char *out;
  size_t out_len;
  int n;
  VALUE ret;
  /* FIXME: Is there any better method to handle this. */
  if(argc < 1)
    {
      rb_raise(rb_eStandardError,"%s","Invalid argument.");
    }

  if(argc < 2)
    {
      cut_code="|";
    }
  else
    {
      cut_code=RSTRING_PTR(argv[1]);
    }
  out_len = RSTRING_LEN(argv[0]) * 2 + 1;
  out = ALLOC_N(char, out_len);
  n = th_brk_line((thchar_t *)RSTRING_PTR(argv[0]), (thchar_t *)out, out_len, cut_code);
  out[n] = '\0';
  ret = rb_str_new2(out);
  free(out);
  return ret;
}


static VALUE
f_th_normalize(VALUE obj,VALUE v_str)
{
  char *ostr;
  size_t ostrlen;
  VALUE ret;
  ostrlen = RSTRING_LEN(v_str) * 2 + 1;
  ostr = ALLOC_N(char, ostrlen);
  th_normalize((thchar_t *)ostr, (thchar_t *)RSTRING_PTR(v_str), ostrlen);
  ret = rb_str_new2(ostr);
  free(ostr);
  return ret;
}

static VALUE
f_th_istis(VALUE obj, VALUE ch)
{
  /* FIXME: a range must be checked? */;
  return (th_istis(NUM2UINT(ch)) ? Qtrue : Qfalse);
}

void
Init_libthai(void)
{
  mLibThai = rb_define_module("LibThai");
  rb_define_module_function(mLibThai, "brk", f_th_brk, 1);
  rb_define_module_function(mLibThai, "brk_line", f_th_brk_line, -1);
  rb_define_module_function(mLibThai, "normalize", f_th_normalize, 1);
  rb_define_module_function(mLibThai, "tis?", f_th_istis, 1);
}
