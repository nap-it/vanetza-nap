/* C++ code produced by gperf version 3.1 */
/* Command-line: gperf --language=C++ --struct-type --readonly-tables jer_transformations.gperf  */
/* Computed positions: -k'3,6,10' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "jer_transformations.gperf"

// Regenerate: gperf --language=C++ --struct-type --readonly-tables jer_transformations.gperf > jer_transformations.cpp
#include "jer_transformations.hpp"
#include <cstring>
namespace vanetza { namespace asn1 { namespace rj {
#line 11 "jer_transformations.gperf"
struct jer_transform_entry_internal { const char* name; double scale; int32_t unavail0, unavail1, unavail2, unavail3; uint8_t unavail_count; };

#define TOTAL_KEYWORDS 37
#define MIN_WORD_LENGTH 6
#define MAX_WORD_LENGTH 29
#define MIN_HASH_VALUE 9
#define MAX_HASH_VALUE 68
/* maximum key range = 60, duplicates = 0 */

class JerTransformHash
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct jer_transform_entry_internal *jer_transform_lookup_internal (const char *str, size_t len);
};

inline unsigned int
JerTransformHash::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 30, 69, 15, 69, 69,
      69, 69, 69, 30, 69, 69,  0, 69, 69, 69,
      69, 69, 69, 10, 69, 69, 30, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69,  0, 69,  0,
      10,  5, 69, 30,  0,  5, 30, 69, 25, 20,
       0,  0, 69, 69,  0,  0,  0, 15, 69, 20,
      15, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
      69, 69, 69, 69, 69, 69
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[9])];
      /*FALLTHROUGH*/
      case 9:
      case 8:
      case 7:
      case 6:
        hval += asso_values[static_cast<unsigned char>(str[5])];
      /*FALLTHROUGH*/
      case 5:
      case 4:
      case 3:
        hval += asso_values[static_cast<unsigned char>(str[2])];
        break;
    }
  return hval;
}

const struct jer_transform_entry_internal *
JerTransformHash::jer_transform_lookup_internal (const char *str, size_t len)
{
  static const struct jer_transform_entry_internal wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 16 "jer_transformations.gperf"
      {"Longitude",                  10000000.0, 1800000001, 0, 0, 0, 1},
      {""}, {""}, {""},
#line 37 "jer_transformations.gperf"
      {"DistanceValue",              100.0, 0, 0, 0, 0, 0},
      {""}, {""},
#line 46 "jer_transformations.gperf"
      {"Radius",                     10.0, 0, 0, 0, 0, 0},
#line 27 "jer_transformations.gperf"
      {"HeadingConfidence",          10.0, 126, 127, 0, 0, 2},
#line 38 "jer_transformations.gperf"
      {"DistanceConfidence",         100.0, 101, 102, 0, 0, 2},
      {""}, {""}, {""},
#line 51 "jer_transformations.gperf"
      {"StandardLength12b",          10.0, 0, 0, 0, 0, 0},
#line 15 "jer_transformations.gperf"
      {"Latitude",                   10000000.0, 900000001,  0, 0, 0, 1},
#line 33 "jer_transformations.gperf"
      {"LateralAccelerationValue",   10.0, 161, 0, 0, 0, 1},
#line 34 "jer_transformations.gperf"
      {"VerticalAccelerationValue",  10.0, 161, 0, 0, 0, 1},
      {""},
#line 31 "jer_transformations.gperf"
      {"AccelerationValue",          10.0, 161, 0, 0, 0, 1},
#line 19 "jer_transformations.gperf"
      {"AltitudeValue",              100.0, 800001, 0, 0, 0, 1},
#line 32 "jer_transformations.gperf"
      {"LongitudinalAccelerationValue", 10.0, 161, 0, 0, 0, 1},
#line 41 "jer_transformations.gperf"
      {"CoordinateConfidence",       100.0, 4096, 0, 0, 0, 1},
      {""},
#line 35 "jer_transformations.gperf"
      {"AccelerationConfidence",     10.0, 102, 0, 0, 0, 1},
#line 47 "jer_transformations.gperf"
      {"SteeringWheelAngleValue",    0.667, 0, 0, 0, 0, 0},
#line 39 "jer_transformations.gperf"
      {"CartesianCoordinate",        100.0, 0, 0, 0, 0, 0},
#line 45 "jer_transformations.gperf"
      {"SemiRangeLength",            10.0, 0, 0, 0, 0, 0},
      {""},
#line 26 "jer_transformations.gperf"
      {"HeadingValue",               10.0, 3601, 0, 0, 0, 1},
#line 17 "jer_transformations.gperf"
      {"DeltaLatitude",              10000000.0, 131072, 0, 0, 0, 1},
#line 40 "jer_transformations.gperf"
      {"CartesianCoordinateLarge",   100.0, 0, 0, 0, 0, 0},
#line 25 "jer_transformations.gperf"
      {"SpeedConfidence",            100.0, 126, 127, 0, 0, 2},
      {""},
#line 21 "jer_transformations.gperf"
      {"SensorHeight",               100.0, 0, 0, 0, 0, 0},
#line 42 "jer_transformations.gperf"
      {"VehicleLengthValue",         10.0, 1023, 0, 0, 0, 1},
#line 18 "jer_transformations.gperf"
      {"DeltaLongitude",             10000000.0, 131072, 0, 0, 0, 1},
#line 49 "jer_transformations.gperf"
      {"TransmissionInterval",       1000.0, 0, 0, 0, 0, 0},
      {""},
#line 43 "jer_transformations.gperf"
      {"VehicleWidth",               10.0, 61, 62, 0, 0, 2},
      {""},
#line 29 "jer_transformations.gperf"
      {"CartesianAngleValue",        10.0, 3601, 0, 0, 0, 1},
#line 22 "jer_transformations.gperf"
      {"SpeedValue",                 100.0, 16383, 0, 0, 0, 1},
      {""},
#line 24 "jer_transformations.gperf"
      {"VelocityComponentValue",     100.0, 16383, 0, 0, 0, 1},
      {""},
#line 50 "jer_transformations.gperf"
      {"SemiAxisLength",             100.0, 4094, 4095, 0, 0, 2},
#line 44 "jer_transformations.gperf"
      {"ObjectDimensionValue",       10.0, 0, 0, 0, 0, 0},
      {""},
#line 36 "jer_transformations.gperf"
      {"YawRateValue",               100.0, 32767, 0, 0, 0, 1},
#line 23 "jer_transformations.gperf"
      {"SpeedValueExtended",         100.0, 16383, 0, 0, 0, 1},
      {""},
#line 28 "jer_transformations.gperf"
      {"WGS84AngleValue",            10.0, 3601, 0, 0, 0, 1},
      {""},
#line 48 "jer_transformations.gperf"
      {"TimestampIts",               1000.0, 0, 0, 0, 0, 0},
      {""}, {""},
#line 30 "jer_transformations.gperf"
      {"AngleConfidence",            10.0, 127, 0, 0, 0, 1},
      {""}, {""},
#line 20 "jer_transformations.gperf"
      {"DeltaAltitude",              100.0, -12700, 12799, 12800, 0, 3}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 52 "jer_transformations.gperf"

const jer_transform_entry* jer_find_transform(const char* name, size_t len) {
    auto* e = JerTransformHash::jer_transform_lookup_internal(name, len);
    return reinterpret_cast<const jer_transform_entry*>(e);
}
}}}